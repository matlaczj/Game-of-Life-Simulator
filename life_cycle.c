#include "service.h"

int birth(int r, int c, cell_t space[r][c], int i, int j)
{
    //a new cell is born! hurray!
    //
    if((space[i]+j)->state == OFF)
        if(count_friends(r,c,space,i,j) == 3)
        {
            (space[i]+j)->next_state = ON;
            return 1;
        }
    return 0;
}

int survival(int r, int c, cell_t space[r][c], int i, int j)
{
    //a cell survives! good job! proud of yaa! :D
    //
    if((space[i]+j)->state == ON)
        if(count_friends(r,c,space,i,j) == 2 || count_friends(r,c,space,i,j) == 3)
        {
            (space[i]+j)->next_state = ON;
            return 1;
        }
    return 0;
}

int death(int r, int c, cell_t space[r][c], int i, int j)
{
    //a cell dies of overcroud! sad reacts only.
    //
    if((space[i]+j)->state == ON)
         if(count_friends(r,c,space,i,j) != 2 && count_friends(r,c,space,i,j) != 3)
         {
             (space[i]+j)->next_state = OFF;
             return 1;
         }
    return 0;
}