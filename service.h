#ifndef SERVICE_H
#define SERVICE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

/*These macros are used in various places to indicate if something is on or off. Its easier this way that to write 1 or 0.
I introduced IRR macro to indicate that something is irrelevant and it will be used for padding's state and next_state and for
cell's is_padding to avoid errors and simplify logic.*/
#define IRR 2
#define ON 1
#define OFF 0

typedef struct cell
{
    char state;
    char next_state;
    char is_padding;
}cell_t;

void prepare_space(int r, int c, cell_t space[r][c]);
void update_space(int r, int c, cell_t space[r][c]);
void print_space(int r, int c, cell_t space[r][c], int wait);
int count_friends(int r, int c, cell_t space[r][c], int i, int j);

int birth(int r, int c, cell_t space[r][c], int i, int j);
int survival(int r, int c, cell_t space[r][c], int i, int j);
int death(int r, int c, cell_t space[r][c], int i, int j);

int glider(int r, int c, cell_t space[r][c], int k, int l);
int froggy(int r, int c, cell_t space[r][c], int k, int l);
int stick(int r, int c, cell_t space[r][c], int k, int l);

int print_png(int r, int c, cell_t space[r][c], FILE* in);

FILE* load_dim(int *, int *, FILE *);
int load(int r, int c, cell_t[r][c], FILE *);
int save(int r, int c, cell_t[r][c], FILE *);

#endif