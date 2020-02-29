#include "service.h"

// since make is not yet working use this to compile easily
// cc main.c toys.c update_states.c count_friends.c life_cycle.c print_space.c prepare_space.c

//SIZE of the sandbox changable in service.h  -- GDZIE??
#define WAIT 200000 //for the animation speed, the bigger the slower the animation is

int main(int argc, char* argv[])
{
    int r = 0;
    int c = 0;
    scanf("%d %d",&r,&c);
    // user gives rows and columns needed but we have to add 2 rows and 2 columns for padding
    r+=2;
    c+=2;
    
    cell_t space[r][c];
    prepare_space(r,c,space);
    
    //creating a funny structure for testing:
    int k,l;
    for(k=1; k<r-1; k+=4)
        for(l=1; l<c-1; l+=4)
        {
//          froggy(r,c,space,k,l);
            stick(r,c,space,k+1,l+1);
        }
    
    print_space(r,c,space, WAIT);
    
    int nrgens = 10000; //number of generations to execute and print
    while(nrgens--)
    {
        int i,j;
        for(i=1; i<r-1; i++)
            for(j=1; j<c-1; j++)
                birth(r,c,space,i,j) || survival(r,c,space,i,j) || death(r,c,space,i,j);    //dla optymalizacji
        update_states(r,c,space);
        print_space(r,c,space, WAIT);
    }
}