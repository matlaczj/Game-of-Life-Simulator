#include "service.h"

//objects for fun, how to use:
//objects have different shapes so imagine they are inside tight rectangle
//indexes k, l are position of that rectangle's left upper cell
//
int glider(int r, int c, cell_t space[r][c], int k, int l)
{
    if(k<0||k>r-1||l<0||l>c-1)
        return 0;
    if(k>r-3||l>c-3)
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
    if(k<0||k>r-1||l<0||l>c-1)
        return 0;
    if(k>r-4||l>c-2)
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
    if(k<0||k>r-1||l<0||l>c-1)
        return 0;
    if(k>r-2||l>c-2)
        return 0;
    space[k][l+1].state = ON;
    space[k+1][l+1].state = ON;
    space[k+2][l+1].state = ON;
    return 1;
}