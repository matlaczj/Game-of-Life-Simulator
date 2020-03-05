#include "service.h"
#include <unistd.h>

void update_space(int r, int c, cell_t space[r][c])
{
    //this function prints the current state of space
    //
    int i,j;
    for(i=1; i<r-1; i++)
    {
        for(j=1; j<c-1; j++)
        {
            //update_state is now here to optimize
            space[i][j].state = space[i][j].next_state;
            space[i][j].next_state = OFF;
            //
        }
        printf("\n");
    } 

}