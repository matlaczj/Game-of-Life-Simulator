#include "service.h"

/*A new cell is born! If the cell is OFF and has 
exactly 3 neighbours this cell comes to life.*/
int birth(int r, int c, cell_t space[r][c], int i, int j)
{
    if((space[i]+j)->state == OFF)
        if(count_friends(r,c,space,i,j) == 3)
        {
            (space[i]+j)->next_state = ON;
            return 1;
        }
    return 0;
}

/*A cell survives! If a cell is ON and has 
exactly 2 or 3 neighbours it stays alive.*/
int survival(int r, int c, cell_t space[r][c], int i, int j)
{
    if((space[i]+j)->state == ON)
    {
        int friends = count_friends(r,c,space,i,j);
        if( friends == 2 || friends == 3)
        {
            (space[i]+j)->next_state = ON;
            return 1;
        }
    }  
    return 0;
}

/*A cell dies. If a cell is ON and has 
less than 2 or more than 3 neighbours its dies.*/
int death(int r, int c, cell_t space[r][c], int i, int j)
{
    if((space[i]+j)->state == ON)
    {
        int friends = count_friends(r,c,space,i,j);
        if(friends != 2 && friends != 3)
         {
             (space[i]+j)->next_state = OFF;
             return 1;
         }
    }  
    return 0;
}