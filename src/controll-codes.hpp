#pragma once

#include <Arduino.h>

const uint8_t REQUEST_CONNECTION = 0x00;
const uint8_t ANSWER_CONNECTION = 0x01;
const uint8_t REQUEST_IMAGE_CHANGE = 0x02;
const uint8_t READY_FOR_IMAGE_CHANGE = 0x03;
const uint8_t SUCCESSFULLY_TRANSMITTED_IMAGE = 0x04;
const uint8_t CONNECTION_CHECK = 0x05;
const uint8_t ANSWER_CONNECTION_CHECK = 0x06;
const uint8_t REQUEST_VERSION = 0x07;
const uint8_t ANSWER_VERSION = 0x08;
