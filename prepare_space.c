#include "service.h"

/*Each element of space gets appropriate values for its members. 
The first if statement is to seperate cells that are padding.*/
void prepare_space(int r, int c, cell_t space[r][c])
{
    int i,j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
        {
            if(i==0 || i==r-1 || j==0 || j==c-1)
            {
                space[i][j].state = IRR; 
                space[i][j].next_state = IRR; 
                space[i][j].is_padding = ON;
            }
            else
            {
                space[i][j].state = OFF;
                space[i][j].next_state = OFF; 
                space[i][j].is_padding = IRR;
            }  
        }
}


