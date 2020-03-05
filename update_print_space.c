#include "service.h"
#include <unistd.h>

/*This function takes space and wait time in microseconds. 
Cleans the screen. Prints appropriate characters for each type of cell.
Later updates this cell's state to its next_state.
After finishing each row prints newline.
After printing the whole space waits for 'wait' time in microseconds.*/
void print_update_space(int r, int c, cell_t space[r][c], int wait)
{
    printf("\e[1;1H\e[2J");
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(space[i][j].state == OFF)
                printf("_ ");
            else if(space[i][j].state == ON)
                printf("# ");
            else 
                printf(". ");
            
            space[i][j].state = space[i][j].next_state;
        }
        printf("\n");
    } 
    usleep(wait);
}