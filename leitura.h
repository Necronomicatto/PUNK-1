#ifndef LEITURA_H
#define LEITURA_H

#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

void parameterTest(int argc);

void OpeningTest(FILE *fp, const char *path, const char *mode);

void readTeams(FILE *fp, Teams *teams, int i);

void readMatches(FILE *fp, Teams *teams, int n);

#endif