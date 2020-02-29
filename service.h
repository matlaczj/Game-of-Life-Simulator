#ifndef SERVICE_H
#define SERVICE_H

#include <stdio.h>
#include <stdlib.h>

#define ON 1 //state of cell, lit or turned off
#define OFF 0

typedef struct cell
{
    int state;
    int next_state;
    int is_padding;
}cell_t;

void prepare_space(int r, int c, cell_t space[r][c]);
void print_space(int r, int c, cell_t space[r][c], int wait);

int count_friends(int r, int c, cell_t space[r][c], int i, int j);
void update_states(int r, int c, cell_t space[r][c]);

int birth(int r, int c, cell_t space[r][c], int i, int j);
int survival(int r, int c, cell_t space[r][c], int i, int j);
int death(int r, int c, cell_t space[r][c], int i, int j);

int glider(int r, int c, cell_t space[r][c], int k, int l);
int froggy(int r, int c, cell_t space[r][c], int k, int l);
int stick(int r, int c, cell_t space[r][c], int k, int l);

#endif