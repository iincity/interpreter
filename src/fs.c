#include <fs.h>
#include <stdio.h>
#include <stdlib.h>

long getFileSize(const char *fileName)
{
    FILE *f = fopen(fileName, "rb");
    if (!f)
        return -1;         // error opening file
    fseek(f, 0, SEEK_END); // rewind cursor to the end of file
    long fsize = ftell(f); // get file size in bytes
    fclose(f);
    return fsize;
}

int readFileToBuffer(const char *fileName, char *buffer, int bufferLength)
{
    FILE *f = fopen(fileName, "rb");
    if (!f)
        return 0; // read 0 bytes from file
    long readBytes = fread(buffer, 1, bufferLength, f);
    fclose(f);
    return readBytes; // number of bytes read
}

int writeStrToFile(const char *fileName, char *buffer)
{
    FILE *fp = fopen(fileName, "w");
    int nwrite = fprintf(fp, "%s", buffer);
    fclose(fp);
    return nwrite;
}
int fileExists(const char *fileName)
{
    FILE *f = fopen(fileName, "rb");
    if (!f)
        return 0; // false: not exists
    fclose(f);
    return 1; // true: exists
}