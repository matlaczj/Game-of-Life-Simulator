#include "service.h"

void load_dim(int *r, int *c, FILE *in){
    if (!fscanf(in, "COLUMNS = %d\n", c)) *c=DEF_SQ_SIDE;
    if (!fscanf(in, "ROWS = %d\n", r)) *r=DEF_SQ_SIDE;
    *r+=2;
    *c+=2;
    return; 
}

int load(int r, int c, cell_t space[r][c], FILE *in){
    char str[1670];
    for (int i=1; i<r-1; i++){
        fscanf(in, "%s\n", str);
        for (int j=1; j<c-1; j++){
            space[i][j].state = str[j-1] - '0';
        }
    }
    return 0;
}

int save(int r, int c, cell_t space[r][c], FILE *in){
    fprintf(in, "COLUMNS = %d\nROWS = %d\n", c, r);
    for (int i=1; i<r-1; i++) {
        fprintf (in, "\n");
        for (int j=1; j<c-1; j++)
            fprintf (in, "%d", space[i][j].state);
    }
}