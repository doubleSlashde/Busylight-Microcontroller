#include <Arduino.h>
#include "availability-status-code.hpp"
#include "controll-codes.hpp"
#include <FastLED.h>

#ifndef NUM_LEDS
#define NUM_LEDS 10
#endif
#ifndef PIXEL_PIN
#define PIXEL_PIN D7
#endif

const String VERSION = "0.0.4";

CRGB leds[NUM_LEDS];
AvailabilityStatusCode availabilityStatusCode;

uint8_t connectionLossCounter;
uint8_t connectionLossCounterRun;
void handleControllCode(uint8_t controllCode);
void handleConnectionLoss();

void setup()
{
  Serial.begin(115200);
  Serial.flush();
  LEDS.addLeds<WS2812B, PIXEL_PIN, GRB>(leds, NUM_LEDS);
  CRGB color = CRGB(0, 0, 0);
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
}

void loop()
{
  if (Serial.available())
  {
    uint8_t controllCode;
    Serial.readBytes(&controllCode, 1);
    handleControllCode(controllCode);
  }
  delay(50);
  connectionLossCounter = connectionLossCounter + 1;
  if (connectionLossCounter > 250 && connectionLossCounterRun < 4)
  {
    connectionLossCounterRun = connectionLossCounterRun + 1;
    handleConnectionLoss();
  }
}

void handleControllCode(uint8_t controllCode)
{
  switch (controllCode)
  {
  case REQUEST_CONNECTION:
    Serial.write(ANSWER_CONNECTION);
    break;

  case CONNECTION_CHECK:
    connectionLossCounter = 0;
    Serial.write(ANSWER_CONNECTION_CHECK);
    break;

  case REQUEST_VERSION:
    Serial.write(ANSWER_VERSION);
    for (int i = 0; i < VERSION.length(); i++)
    {
      Serial.write(VERSION[i]);
    }
    Serial.write('\0');
    break;

  case REQUEST_IMAGE_CHANGE:
    Serial.write(READY_FOR_IMAGE_CHANGE);
    while (Serial.available() < 2)
      ;
    uint8_t *data = new uint8_t[2];

    Serial.readBytes(data, 2);
    FastLED.setBrightness(data[0]);
    int numberOfLeds = data[1];

    while (Serial.available() < numberOfLeds * 3)
      ;
    delete[] data;
    data = new uint8_t[numberOfLeds * 3];
    Serial.readBytes(data, numberOfLeds * 3);

    for (int i = 0; i < numberOfLeds; i++)
    {
      int colorStartIndex = i * 3;
      leds[i] = CRGB(data[colorStartIndex], data[colorStartIndex + 1], data[colorStartIndex + 2]);
    }

    delete[] data;
    FastLED.show();
    Serial.write(SUCCESSFULLY_TRANSMITTED_IMAGE);
    connectionLossCounterRun = 0;
    connectionLossCounter = 0;
    break;
  }
}

void handleConnectionLoss()
{
  const int numberOfSignals = 5;
  const int delayInMs = 300;
  CRGB color_Blue = CRGB(0, 0, 150);
  CRGB color_Off = CRGB(0, 0, 0);

  for (int i = 0; i < numberOfSignals; i++)
  {
    fill_solid(leds, NUM_LEDS, color_Blue);
    FastLED.show();
    delay(delayInMs);

    fill_solid(leds, NUM_LEDS, color_Off);
    FastLED.show();
    delay(delayInMs);

    connectionLossCounter = 0;
  }
}
