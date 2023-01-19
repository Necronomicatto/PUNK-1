#include "leitura.h"
#include "structs.h"
#include "processor.h"
#include <stdio.h>
#include <stdlib.h>

void parameterTest(int argc){                                                                       //testa se o comando foi digitado corretamente
    if (argc != 3) {
        printf("Use: ./executavel <arquivoEntrada> <arquivoSaida>");
        exit(0);
    }
}

void OpeningTest(FILE *fp, const char *path, const char *mode){                   //verifica se o arquivo existe e se pode ser aberto com o modo

    if (fp == NULL) {
        printf("Falha em abrir o arquivo %s com o modo %s\n", path, mode);
        exit(0);
    }
}

void readTeams(FILE *fp, Teams *teams, int i){                                                 //cria os times de acordo com a quantidade especificada e ja atribui valores iniciais

    for (int j=0; j<i; j++){
        fscanf(fp,"%s",teams[j].Name);
        fgetc(fp);
        teams[j].total=0;
        teams[j].games=0;
        teams[j].wins=0;
        teams[j].goodGoals=0;
        teams[j].badGoals=0;
    }
}

void readMatches(FILE *fp, Teams *teams, int n){                                            //lê as partidas e rodadas e armazena os valores
    char border[4];
    for(int rounds = 1; rounds <= 2*(n-1); rounds++){
        fscanf(fp,"%s",border);
        fgetc(fp);
        for(int matches = 1; matches <= n/2; matches++){
            controlMatches(fp, teams, n);
        }
    }
}

