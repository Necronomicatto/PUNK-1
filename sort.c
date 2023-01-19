#include "sort.h"
#include <string.h>

int compare (Teams t1, Teams t2)                                 //compara os valores das structs para ver qual é maior para ordenar
{
    if(t1.total>t2.total){
        return 1;        
    } else if(t1.total<t2.total){
        return 0;
    } else if(t1.total==t2.total){
        if(t1.wins>t2.wins){
            return 1;
        } else if(t1.wins<t2.wins){
            return 0;
        } else if(t1.wins==t2.wins){
            if((t1.goodGoals-t1.badGoals)>(t2.goodGoals-t2.badGoals)){
                return 1;
            } else if((t1.goodGoals-t1.badGoals)<(t2.goodGoals-t2.badGoals)){
                return 0;
            } else if((t1.goodGoals-t1.badGoals)==(t2.goodGoals-t2.badGoals)){
                if(t1.goodGoals<t2.goodGoals){
                    return 1;
                } else if(t1.goodGoals>t2.goodGoals){
                    return 0;
                }
            }
        }
    }     
}

void sort (Teams* list, int n)                                      //ordena os times
{
    for (int counter = 0; counter< n-1;counter++)
    {
        for (int j = 0;j<n-1;j++)
            if (compare(list[j],list[j+1])==0)
            {
                Teams temp = list [j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
    }
} 