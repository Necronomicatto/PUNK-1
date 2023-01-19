#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "leitura.h"
#include "processor.h"
#include "sort.h"
#include "saida.h"

int main(int argc, char *argv[]){
    int n;

    parameterTest(argc);

    FILE *in, *out;
    in = fopen(argv[1], "r");
    OpeningTest(in, argv[1], "r");

    fscanf(in,"%d",&n);
    fgetc(in);
    Teams time[n];
    readTeams(in, time, n);
    readMatches(in, time, n);
    sort(time, n);
    
    out = fopen(argv[2],"w");
    printFile(out, time, n);
    fclose (out);
    fclose(in);
    return 0;
}