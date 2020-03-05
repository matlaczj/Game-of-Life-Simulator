#include "service.h"

void prepare_space(int r, int c, cell_t space[r][c])
{
    // each element of space gets appropriate values for its members
    // last 3 if's are for debugging, can be erased later
    // we wont need state or next_state for padding but we dont want random values there
    //

    //troche zmienilem kod, zeby dla kazdej komorki nie sprawdzalo 4 warunkow

    int i,j;
       for(j=0; j<c; j++) {
        space[0][j].state = OFF; 
        space[0][j].next_state = OFF; 
        space[0][j].is_padding = ON;
        space[r-1][j].state = OFF; 
        space[r-1][j].next_state = OFF; 
        space[r-1][j].is_padding = ON;
    }

    for(i=1; i<r-1; i++) {
        space[i][0].state = OFF; 
        space[i][0].next_state = OFF; 
        space[i][0].is_padding = ON;
        space[i][c-1].state = OFF; 
        space[i][c-1].next_state = OFF; 
        space[i][c-1].is_padding = ON;

        for(j=1; j<c-1; j++)
        {
/*            if(i==0 || i==r-1  || j==0 || j==c-1 )
            {
                space[i][j].state = OFF; 
                space[i][j].next_state = OFF; 
                space[i][j].is_padding = ON;
            }
            else
            {   */
            space[i][j].state = OFF;
            space[i][j].next_state = OFF; 
            space[i][j].is_padding = OFF;
//            }
#ifdef DEBUG            
            if(space[i][j].state != OFF)
                printf("\nspace[%d][%d].state has wrong value: %d\n",i,j,space[i][j].state);
            if(space[i][j].next_state != OFF)
                printf("\nspace[%d][%d].next_state has wrong value: %d\n",i,j,space[i][j].next_state);
            if(space[i][j].is_padding != OFF && space[i][j].is_padding != ON )
                printf("\nspace[%d][%d].is_padding has wrong value: %d\n",i,j,space[i][j].next_state);
#endif            
        }
    }
}


