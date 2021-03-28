#include <stdio.h>
#include <fileManager.h>
#include <assembly.h>

int main()
{
    char* fileName = "test.txt";
    char* buffer;
    int code = input(fileName, &buffer);
    deleteComments(buffer, ';');
    parseResult result = parse(buffer, "\n\r, ");

    for (int i = 0; i < result.size; ++i)
        printf("%s\n", result.parsedBuffer[i]);

    return 0;
}