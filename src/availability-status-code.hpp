#pragma once

#include <Arduino.h>

#define STATUS_OFF 0
#define STATUS_AVAILABLE 1
#define STATUS_BUSY 2
#define STATUS_DO_NOT_DISTURB 3

class AvailabilityStatusCode
{
public:
    uint8_t getStatusCode();
    void toggleStatusCode();

private:
    uint8_t statusCode = 0;
};
