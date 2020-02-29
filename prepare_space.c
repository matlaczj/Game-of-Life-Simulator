#include "service.h"

void prepare_space(int r, int c, cell_t space[r][c])
{
    // each element of space gets appropriate values for its members
    // last 3 if's are for debugging, can be erased later
    // we wont need state or next_state for padding but we dont want random values there
    //
    int i,j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
        {
            if(i==0 || i==r-1 || j==0 || j==c-1)
            {
                space[i][j].state = OFF; 
                space[i][j].next_state = OFF; 
                space[i][j].is_padding = ON;
            }
            else
            {
                space[i][j].state = OFF;
                space[i][j].next_state = OFF; 
                space[i][j].is_padding = OFF;
            }
            
            if(space[i][j].state != OFF)
                printf("\nspace[%d][%d].state has wrong value: %d\n",i,j,space[i][j].state);
            if(space[i][j].next_state != OFF)
                printf("\nspace[%d][%d].next_state has wrong value: %d\n",i,j,space[i][j].next_state);
            if(space[i][j].is_padding != OFF && space[i][j].is_padding != ON )
                printf("\nspace[%d][%d].is_padding has wrong value: %d\n",i,j,space[i][j].next_state);
            
        }
}


