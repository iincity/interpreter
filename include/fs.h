#pragma once

int readFileToBuffer(const char *fileName, char *buffer, int bufferLength);
long getFileSize(const char *fileName);
int writeStrToFile(const char *fileName, char *buffer);
int fileExists(const char *fileName);