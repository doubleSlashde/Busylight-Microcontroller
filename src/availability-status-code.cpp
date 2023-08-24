#include "availability-status-code.hpp"

uint8_t AvailabilityStatusCode::getStatusCode()
{
    return statusCode;
}

void AvailabilityStatusCode::toggleStatusCode()
{
    statusCode++;
    if (statusCode > 3)
    {
        statusCode = 0;
    }
}
