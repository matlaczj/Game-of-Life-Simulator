#include "service.h"

void update_states(int r, int c, cell_t space[r][c])
{
    //changes states of all cells for their planned states "next_state" and changes
    //their planned states to NONE
    //
    int i,j;
    for(i=1; i<r-1; i++)
        for(j=1; j<c-1; j++)
//       {
            space[i][j].state = space[i][j].next_state;
//          space[i][j].next_state = OFF;   // niepotrzebne
//        }
}