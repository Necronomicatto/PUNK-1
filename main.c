#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"

struct Teams {
    int position;
    char Name[30];
    int total;
    int games;
    int wins;
    int goodGoals;
    int badGoals;
};

void readTeams(FILE *fp){
    int i;
    fscanf(fp,"%d",&i);
    struct Teams teams[i];
    for (int j=0; j<i; j++){
        fscanf(fp,"%s",teams[j].Name);
    }
    for (int x=0; x<i; x++){
        printf("%s\n",teams[x].Name);
    }

}

int main(int argc, char *argv[]){
    //parameterTest(argc);
    FILE *fp = fopen("entrada.txt", "r");
    OpeningTest(fp, argv[1], "r");
    readTeams(fp);
    fclose(fp);
    return 0;
}