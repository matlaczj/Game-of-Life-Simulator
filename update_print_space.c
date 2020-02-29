#include "service.h"
#include <unistd.h>

void update_print_space(int r, int c, cell_t space[r][c], int wait)
{
    //this function prints the current state of space
    //
    printf("\e[1;1H\e[2J");
    int i,j;
    for(i=1; i<r-1; i++)
    {
        for(j=1; j<c-1; j++)
        {
            //update_state is now here to optimize
            space[i][j].state = space[i][j].next_state;
            space[i][j].next_state = OFF;
            //
            if(space[i][j].state == OFF)
                printf("_ ");
            else if(space[i][j].state == ON)
                printf("# ");
            else 
            {
                printf("\nspace[%d][%d].state has wrong value: %d\n",i,j,space[i][j].state);
            }
        }
        printf("\n");
    } 
    usleep(wait);
}