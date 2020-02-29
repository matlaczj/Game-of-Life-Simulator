#include "service.h"

//objects for fun, how to use:
//objects have different shapes so imagine they are inside tight rectangle perimeter
//indexes k, l are position of that rectangle's left upper cell
//
int glider(int r, int c, cell_t space[r][c], int k, int l)
{
    int re_per = 3; // rectangle perimeter
    if(k<1 || k>r-re_per-1 || l<1 || l>r-re_per-1)
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
    int re_per = 4;
    if(k<1 || k>r-re_per-1 || l<1 || l>r-re_per-1)
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
    int re_per = 3;
    if(k<1 || k>r-re_per-1 || l<1 || l>r-re_per-1)
        return 0;
    space[k][l+1].state = ON;
    space[k+1][l+1].state = ON;
    space[k+2][l+1].state = ON;
    return 1;
}