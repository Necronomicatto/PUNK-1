#include "leitura.h"
#include <stdio.h>
#include <stdlib.h>

void parameterTest(int argc){
    if (argc != 2) {
        printf("Uso: ./executavel <arquivo>");
        exit(0);
    }
}

void OpeningTest(FILE *fp, const char *path, const char *mode){
    if (fp == NULL) {
        printf("Falha em abrir o arquivo %s com o modo %s\n", path, mode);
        exit(0);
    }
}

void printFile(FILE *fp){
    char c;
    while (fscanf(fp, "%c", &c) != EOF){
        printf("%c", c);
    }    
}