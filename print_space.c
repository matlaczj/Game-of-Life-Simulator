#include "service.h"
#include <unistd.h>

void print_space(int r, int c, cell_t space[r][c], int wait) {
    printf("\e[1;1H\e[2J");
    int i,j;
    for(i=1; i<r-1; i++)
    {
        for(j=1; j<c-1; j++)
        {
            if(space[i][j].state == OFF)
                printf("_ ");
            else if(space[i][j].state == ON)
                printf("# ");
#ifdef DEBUG
            else 
            {  
                printf("\nspace[%d][%d].state has wrong value: %d\n",i,j,space[i][j].state);
            }
#endif
        }
        puts('\n');
    }            
    usleep(wait);
        
}