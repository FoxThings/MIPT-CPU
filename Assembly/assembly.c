#include <assembly.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

parseResult parse(char* buffer, char* separators)
{ 
    assert(buffer     != NULL);
    assert(separators != NULL);

    char* pointer      = strtok(buffer, separators);
    parseResult result = {};
    result.size        = 1;
    result.errorCode   = OK;
    int _size          = 10;

    result.parsedBuffer = (char**) calloc(_size, sizeof(char*));
    if (result.parsedBuffer == NULL)
    {
        result.errorCode = OUT_OF_MEMORY;
        return result;
    }
    result.parsedBuffer[result.size - 1] = pointer;
 
    while (pointer != NULL)
    {
        pointer = strtok(NULL, separators);
        ++result.size;

        if (_size < result.size)
        {
            _size *= 2;
            result.parsedBuffer = (char**) realloc(result.parsedBuffer, _size * sizeof(char*));
            if (result.parsedBuffer == NULL)
            {
                result.errorCode = OUT_OF_MEMORY;
                return result;
            }
        }

        result.parsedBuffer[result.size - 1] = pointer;
    }
    return result;
}

errorCode deleteComments(char* buffer, char commentFlag)
{

    assert(buffer != NULL);
    if ((commentFlag >= '0' && commentFlag <= '9') ||
        (commentFlag >= 'A' && commentFlag <= 'Z') || 
        (commentFlag >= 'a' && commentFlag <= 'z') ||
        commentFlag == ':'  || commentFlag == ',')
            return INVALID_ARGUMENT;

    char* pointer = NULL;
    while ((pointer = strchr(buffer, commentFlag)) != NULL)
    {
        while (*pointer != '\n' && *pointer != '\0')
        {
            *pointer = ' ';
            ++pointer;
        }
        
    }
    return OK;
}