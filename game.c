#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct cell
{
    struct cell* pointers[8];
    int state;
    int next_state;
}cell_t;

#define WAIT 200000 //for the animation speed, the bigger the slower the animation is
#define SIZE 10 //size of the sandbox
#define ON 1 //state of cell, lit or turned off
#define OFF 0
//for easier management of directions in "pointers":
#define LEWO 0
#define PRAWO 1
#define GORA 2
#define DOL 3
#define LEWOGORA 4
#define PRAWOGORA 5
#define LEWODOL 6
#define PRAWODOL 7

void fill_pointers(cell_t space[SIZE][SIZE], int size);
void print_space(cell_t space[SIZE][SIZE], int size);
int count_friends(cell_t* cell);
void initial_conditions(cell_t space[SIZE][SIZE], int size);
void update_states(cell_t space[SIZE][SIZE], int size);
int birth(cell_t* cell);
int survival(cell_t* cell);
int death(cell_t* cell);

int main(int argc, char* argv[])
{
    cell_t space[SIZE][SIZE];
    fill_pointers(space,SIZE);
    initial_conditions(space,SIZE);
    
    //glider:
    space[1][1].state = ON;
    space[2][2].state = ON;
    space[3][1].state = ON;
    space[3][2].state = ON;
    space[2][3].state = ON;
    print_space(space, SIZE);
    
    int still_running = 1;
    while(still_running)
    {
        still_running = 0;
        int i,j;
        for(i=0; i<SIZE; i++)
            for(j=0; j<SIZE; j++)
            {
                if(birth(space[i]+j)) still_running++;
                if(survival(space[i]+j)) still_running++;
                death(space[i]+j);
            }
        
        update_states(space, SIZE);
        print_space(space, SIZE);
        
    }
}

void fill_pointers(cell_t space[SIZE][SIZE], int size)
{
    //this function gives every cell easy information about pointers to their neighbours, they are all inside this cell's "pointers" array, Moore's neighbourhood 
    //
    int i,j;
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        {
            //4 corners of matrix:
            if(i==0 && j==0) //left up
            {
                space[i][j].pointers[LEWO]=NULL;
                space[i][j].pointers[PRAWO]=space[i]+j+1;
                space[i][j].pointers[GORA]=NULL;
                space[i][j].pointers[DOL]=space[i+1]+j;
                space[i][j].pointers[LEWOGORA]=NULL;
                space[i][j].pointers[PRAWOGORA]=NULL;
                space[i][j].pointers[LEWODOL]=NULL;
                space[i][j].pointers[PRAWODOL]=space[i+1]+j+1;
            }
            if(i==0 && j==size-1) //right up
            {
                space[i][j].pointers[LEWO]=space[i]+j-1;
                space[i][j].pointers[PRAWO]=NULL;
                space[i][j].pointers[GORA]=NULL;
                space[i][j].pointers[DOL]=space[i+1]+j;
                space[i][j].pointers[LEWOGORA]=NULL;
                space[i][j].pointers[PRAWOGORA]=NULL;
                space[i][j].pointers[LEWODOL]=space[i+1]+j-1;
                space[i][j].pointers[PRAWODOL]=NULL;
            }
            if(i==size-1 && j==0) //left down
            {
                space[i][j].pointers[LEWO]=NULL;
                space[i][j].pointers[PRAWO]=space[i]+j+1;
                space[i][j].pointers[GORA]=space[i-1]+j;
                space[i][j].pointers[DOL]=NULL;
                space[i][j].pointers[LEWOGORA]=NULL;
                space[i][j].pointers[PRAWOGORA]=space[i-1]+j+1;
                space[i][j].pointers[LEWODOL]=NULL;
                space[i][j].pointers[PRAWODOL]=NULL;
            }
            if(i==size-1 && j==size-1) //right down
            {
                space[i][j].pointers[LEWO]=space[i]+j-1;
                space[i][j].pointers[PRAWO]=NULL;
                space[i][j].pointers[GORA]=space[i-1]+j;
                space[i][j].pointers[DOL]=NULL;
                space[i][j].pointers[LEWOGORA]=space[i-1]+j-1;
                space[i][j].pointers[PRAWOGORA]=NULL;
                space[i][j].pointers[LEWODOL]=NULL;
                space[i][j].pointers[PRAWODOL]=NULL;
            }
            //egdes (without corners):
            if(i==0 && j>0 && j<size-1) //up edge
            {
                space[i][j].pointers[LEWO]=space[i]+j-1;
                space[i][j].pointers[PRAWO]=space[i]+j+1;
                space[i][j].pointers[GORA]=NULL;
                space[i][j].pointers[DOL]=space[i+1]+j;
                space[i][j].pointers[LEWOGORA]=NULL;
                space[i][j].pointers[PRAWOGORA]=NULL;
                space[i][j].pointers[LEWODOL]=space[i+1]+j-1;
                space[i][j].pointers[PRAWODOL]=space[i+1]+j+1;
            }
            if(i==size-1 && j>0 && j<size-1) //down edge
            {
                space[i][j].pointers[LEWO]=space[i]+j-1;
                space[i][j].pointers[PRAWO]=space[i]+j+1;
                space[i][j].pointers[GORA]=space[i-1]+j;
                space[i][j].pointers[DOL]=NULL;
                space[i][j].pointers[LEWOGORA]=space[i-1]+j-1;
                space[i][j].pointers[PRAWOGORA]=space[i-1]+j+1;
                space[i][j].pointers[LEWODOL]=NULL;
                space[i][j].pointers[PRAWODOL]=NULL;
            }
            if(i>0 && i<size-1 && j==0) //left edge
            {
                space[i][j].pointers[LEWO]=NULL;
                space[i][j].pointers[PRAWO]=space[i]+j+1;
                space[i][j].pointers[GORA]=space[i-1]+j;
                space[i][j].pointers[DOL]=space[i+1]+j;
                space[i][j].pointers[LEWOGORA]=NULL;
                space[i][j].pointers[PRAWOGORA]=space[i-1]+j+1;
                space[i][j].pointers[LEWODOL]=NULL;
                space[i][j].pointers[PRAWODOL]=space[i+1]+j+1;
            }
            if(i>0 && i<size-1 && j==size-1) //right edge
            {
                space[i][j].pointers[LEWO]=space[i]+j-1;
                space[i][j].pointers[PRAWO]=NULL;
                space[i][j].pointers[GORA]=space[i-1]+j;
                space[i][j].pointers[DOL]=space[i+1]+j;
                space[i][j].pointers[LEWOGORA]=space[i-1]+j-1;
                space[i][j].pointers[PRAWOGORA]=NULL;
                space[i][j].pointers[LEWODOL]=space[i+1]+j-1;
                space[i][j].pointers[PRAWODOL]=NULL;
            }
            //midst:
            else
            {
                space[i][j].pointers[LEWO]=space[i]+j-1;
                space[i][j].pointers[PRAWO]=space[i]+j+1;
                space[i][j].pointers[GORA]=space[i-1]+j;
                space[i][j].pointers[DOL]=space[i+1]+j;
                space[i][j].pointers[LEWOGORA]=space[i-1]+j-1;
                space[i][j].pointers[PRAWOGORA]=space[i-1]+j+1;
                space[i][j].pointers[LEWODOL]=space[i+1]+j-1;
                space[i][j].pointers[PRAWODOL]=space[i+1]+j+1;
            }
        }
}
void print_space(cell_t space[SIZE][SIZE], int size)
{
    //this function prints the current state of space
    //
    printf("\e[1;1H\e[2J");
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(space[i][j].state == OFF)
                printf("_ ");
            else if(space[i][j].state == ON)
                printf("# ");
            else 
            {
                printf("space[%d][%d].state is wrong value: %d\n",i,j,space[i][j].state);
            }
        }
        printf("\n");
    } 
    usleep(WAIT);
}
void initial_conditions(cell_t space[SIZE][SIZE], int size)
{
    //this function sets the deafult state and next state for each cell on 2D matrix
    //
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            space[i][j].state = OFF;
            space[i][j].next_state = OFF; 
        }
    }
}
int count_friends(cell_t* cell) 
{
    int i;
    int count = 0;
    for(i=0; i<8; i++)
    {
        if(cell->pointers[i] != NULL)
            if(cell->pointers[i]->state == ON)
                count++;
    }
    return count;
}
void update_states(cell_t space[SIZE][SIZE], int size)
{
    //changes states of all cells for their planned states "next_state" and changes
    //their planned states to NONE
    //
    int i,j;
    for(i=0; i<size; i++)
        {
            for(j=0; j<size; j++)
            {
                space[i][j].state = space[i][j].next_state;
            }
        }
}
int birth(cell_t* cell)
{
    //a new cell is born! hurray!
    //
    if(cell->state == OFF)
        if(count_friends(cell) == 3)
        {
            cell->next_state = ON;
            return 1;
        }
    return 0;
}
int survival(cell_t* cell)
{
    //a cell survives! good job! proud of yaa! :D
    //
    if(cell->state == ON)
        if(count_friends(cell) == 2 || count_friends(cell) == 3)
        {
            cell->next_state = ON;
            return 1;
        }
    return 0;
}
int death(cell_t* cell)
{
    //a cell dies of overcroud! sad reacts only.
    //
    if(cell->state == ON)
         if(count_friends(cell) != 2 && count_friends(cell) != 3)
         {
             cell->next_state = OFF;
             return 1;
         }
    return 0;
}