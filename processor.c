#include "processor.h"
#include <string.h>

void searchTeam(char* time, int golsFavor, int golsContra, int Vitoria, int Pontos,  Teams *teams, int i){        //procura o time nas structs utilizando seu nome
    for (int a=0; a < i; a++){
        if(strcmp(time, teams[a].Name)==0){
            teams[a].goodGoals = teams[a].goodGoals+golsFavor;
            teams[a].badGoals = teams[a].badGoals+golsContra;
            teams[a].wins = teams[a].wins+Vitoria;
            teams[a].total = teams[a].total+Pontos;
            teams[a].games++;
            break;
        }
    }
}

void controlMatches(FILE *fp,  Teams *teams, int i){                                //função auxiliar para a leitura das partidas
    char time_1[21];
    char time_2[21];
    int gols_1;
    int gols_2;
    int vitoria_1=0;
    int vitoria_2=0;
    int pontos_1=0;
    int pontos_2=0;
    fscanf(fp,"%s %d x %d %s", time_1, &gols_1, &gols_2, time_2);
    if(gols_1>gols_2){
        vitoria_1++;
        pontos_1+=3;
    } else if(gols_1<gols_2){
        vitoria_2++;
        pontos_2+=3;
    } else if(gols_1==gols_2){
        pontos_1++;
        pontos_2++;
    }
    searchTeam(time_1, gols_1, gols_2, vitoria_1, pontos_1, teams, i);
    searchTeam(time_2, gols_2, gols_1, vitoria_2, pontos_2, teams, i); 
}