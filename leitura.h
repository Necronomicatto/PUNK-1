#ifndef LEITURA_H
#define LEITURA_H
#include <stdlib.h>
#include <stdio.h>

void parameterTest(int argc);

void OpeningTest(FILE *fp, const char *path, const char *mode);

void printFile(FILE *fp);

#endif