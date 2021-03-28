#pragma once

typedef enum errorCode
{
    OK = 0,
    CANNOT_OPEN_FILE,
    CANNOT_READ_FILE,
    OUT_OF_MEMORY,
    INVALID_ARGUMENT
} errorCode;