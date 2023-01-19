#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Teams {       //struct para criação e armazenamento dos dados dos times
    char Name[21];
    int total;
    int games;
    int wins;
    int goodGoals;
    int badGoals;
}Teams;

#endif