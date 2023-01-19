#include "saida.h"
#include "structs.h"
#include "processor.h"
#include <stdio.h>
#include <stdlib.h>

void printFile(FILE *fp, Teams *teams, int n) {                      //imprime os valores no arquivo de saida
    for (int x=0; x<n; x++){
        fprintf(fp,"%d %s %d %d %d %d %d %d\n",x+1,teams[x].Name, teams[x].total,
         teams[x].games,  teams[x].wins,  teams[x].goodGoals -  teams[x].badGoals ,  teams[x].goodGoals,  teams[x].badGoals);
    }
}