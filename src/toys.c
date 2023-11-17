#include "service.h"

/*These functions puts some objects in the space. They have different shapes but imagine 
a square around them - this square's dimension is equal to sq_per square perimeter.
Functions take space and indexes of the upper leftmost cell of that square.
There is if statement thats supposed to prevent illegal positions like padding or 
if it wouldnt fit the space.*/

int glider(int r, int c, cell_t space[r][c], int k, int l)
{
    int sq_per = 3;
    if(sq_per>r-2 || sq_per>c-2 || k<1 || k>r-sq_per-1 || l<1 || l>c-sq_per-1)
        return 0;
    space[k][l].state = ON;
    space[k+1][l+1].state = ON;
    space[k+2][l].state = ON;
    space[k+2][l+1].state = ON;
    space[k+1][l+2].state = ON;
    return 1;
}

int froggy(int r, int c, cell_t space[r][c], int k, int l)
{
    int sq_per = 4;
    if(sq_per>r-2 || sq_per>c-2 || k<1 || k>r-sq_per-1 || l<1 || l>c-sq_per-1)
        return 0;
    space[k][l+1].state = ON;
    space[k+1][l+1].state = ON;
    space[k+2][l+1].state = ON;
    space[k+1][l+2].state = ON;
    space[k+2][l+2].state = ON;
    space[k+3][l+2].state = ON;
    return 1;
}

int stick(int r, int c, cell_t space[r][c], int k, int l)
{
    int sq_per = 3;
    if(sq_per>r-2 || sq_per>c-2 || k<1 || k>r-sq_per-1 || l<1 || l>c-sq_per-1)
        return 0;
    space[k][l+1].state = ON;
    space[k+1][l+1].state = ON;
    space[k+2][l+1].state = ON;
    return 1;
}