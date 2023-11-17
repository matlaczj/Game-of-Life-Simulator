#include "service.h"
/*Each element of space gets appropriate values for its members. 
The first if statement is to seperate cells that are padding.*/

void prepare_space(int r, int c, cell_t space[r][c])
{
    // each element of space gets appropriate values for its members
    // last 3 if's are for debugging, can be erased later
    // we wont need state or next_state for padding but we dont want random values there
    //

    // nie ma moim zdaniem sensu optymalizowac tak mocno czegos co sie wykonuje tylko 1 raz w programie
    // a bardzo mocno spada czytelnosc i mozliwosc bledu wzrasta a zysk znikomy, zmienilem tez troche debugging 
    // bo wydawal mi sie dziwny, teraz chodzi o sprawdzenie czy jakims cudem jakas niemozliwa wartosc nie dostala sie do ktorejs // komorki 
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
            
            #ifdef DEBUG 
            if(space[i][j].state != OFF & space[i][j].state != ON && space[i][j].state != IRR )
                printf("\nspace[%d][%d].state has impossible value: %d\n",i,j,space[i][j].state);
            if(space[i][j].next_state != OFF & space[i][j].next_state != ON && space[i][j].next_state != IRR )
                printf("\nspace[%d][%d].state has impossible value: %d\n",i,j,space[i][j].next_state);
            if(space[i][j].is_padding != OFF & space[i][j].is_padding != ON && space[i][j].is_padding != IRR )
                printf("\nspace[%d][%d].state has impossible value: %d\n",i,j,space[i][j].is_padding);
            #endif
        }
}


