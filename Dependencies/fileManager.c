#include <fileManager.h>
#include <errorCodes.h>
#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include <assert.h>

errorCode input(const char* name, char** buffer)
{
    assert(name   != NULL);
    assert(buffer != NULL);

    FILE* fin;
    if ((fin = fopen(name, "r")) == NULL)
    {
        return CANNOT_OPEN_FILE;
    }

    struct stat info;
    if(stat(name, &info)) return CANNOT_OPEN_FILE;

    *buffer = (char*) calloc(info.st_size + 1, sizeof(char));
    if (buffer == NULL)
        return OUT_OF_MEMORY;

    size_t size = fread(*buffer, sizeof(char), info.st_size, fin);
    if (size < 0)
        return CANNOT_READ_FILE;

    fclose(fin);
    return OK;
}