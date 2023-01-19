#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "structs.h"
#include <stdio.h> 
#include <string.h>

void searchTeam(char* time, int golsFavor, int golsContra, int Vitoria, int Pontos,  Teams *teams, int i);

void controlMatches(FILE *fp,  Teams *teams, int i);

#endif