#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

typedef struct Teams {
    int position;
    char Name[20];
    int total;
    int games;
    int wins;
    int goodGoals;
    int badGoals;
}Teams;

void readTeams(FILE *fp, Teams *teams, int i){

    for (int j=0; j<i; j++){
        fscanf(fp,"%s",teams[j].Name);
        fgetc(fp);
        teams[j].total=0;
        teams[j].games=0;
        teams[j].wins=0;
        teams[j].goodGoals=0;
        teams[j].badGoals=0;
    }
    for (int x=0; x<i; x++){
        printf("%s\n",teams[x].Name);
    }

}

void searchTeam(char* time, int golsFavor, int golsContra, int Vitoria, int Pontos,  Teams *teams, int i){
    for (int a=0; a < i; a++){
        printf("querido :%s\n",time);
        printf ("procurado :%s\t",teams[a].Name);
        printf("Igual? %s\n",(strcmp(time, teams[a].Name)==0?"Yes, daddy":"no,bitch"));
        if(strcmp(time, teams[a].Name)==0){
            puts ("Mate seu patrao");
            teams[a].goodGoals = teams[a].goodGoals+golsFavor;
            teams[a].badGoals = teams[a].badGoals+golsContra;
            teams[a].wins = teams[a].wins+Vitoria;
            teams[a].total = teams[a].total+Pontos;
            teams[a].games++;
            printf("resultado: %s --- fv:%d ct:%d win:%d total:%d games:%d\n",teams[a].Name,teams[a].goodGoals,
            teams[a].badGoals,teams[a].wins,teams[a].total,teams[a].games );
            break;

        }

    }
}

void controlMatches(FILE **fp,  Teams *teams, int i){
    char time_1[20];
    char time_2[20];
    int gols_1;
    int gols_2;
    int vitoria_1=0;
    int vitoria_2=0;
    int pontos_1=0;
    int pontos_2=0;
    fscanf(*fp,"%s %d x %d %s", time_1, &gols_1, &gols_2, time_2);
    if(fgetc(*fp)=='\n') puts("Yes baby");
   // fgetc(fp);
    printf("partida: %s %d x %d %s\n", time_1, gols_1, gols_2, time_2);
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
int compare (Teams t1, Teams t2)
{
    
}
void sort (Teams* list)
{
    for (int i = 0; i< n-1;i++)
    {
        for (int j = i+1;j-1-i;j++)
            if (compare(list[i],list[j]))
            {
                Teams temp = list [i];
                list[i] = list[j];
                list[j] = list[i];
            }
    }
} 
int main(int argc, char *argv[]){
    int n;
    char border[4];
    //parameterTest(argc);
    FILE *fp = fopen("entrada.txt", "r");
    OpeningTest(fp, argv[1], "r");

    fscanf(fp,"%d",&n);
    fgetc(fp);
     Teams time[n];
    readTeams(fp, time, n);

    for(int rounds = 1; rounds <= 2*(n-1); rounds++){
        fscanf(fp,"%s",border);
        fgetc(fp);
        for(int matches = 1; matches <= n/2; matches++){
            controlMatches(&fp, time, n);
        }
    }
    FILE *out = fopen("out.txt","w");
    for (int x=0; x<n; x++){
        fprintf(out,"%d %s %d %d %d %d %d %d\n",x+1,time[x].Name, time[x].total,
         time[x].games,  time[x].wins,  time[x].goodGoals -  time[x].badGoals ,  time[x].goodGoals,  time[x].badGoals);
    }
    fclose (out);
    fclose(fp);
    return 0;
}