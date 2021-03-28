#pragma once
#include <errorCodes.h>

typedef struct parseResult
{
    char** parsedBuffer;
    int size;
    errorCode errorCode;
} parseResult;


parseResult parse(char* buffer, char* separators);
errorCode deleteComments(char* buffer, char commentFlag);
