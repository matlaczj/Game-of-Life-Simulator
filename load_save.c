#include "service.h"

FILE* load_dim(int *r, int *c, FILE *in){
    if (!fscanf(in, "COLUMNS = %d\n", c)) *c=10;
    if (!fscanf(in, "ROWS = %d\n", r)) *r=10;
    *r+=2;
    *c+=2;
    return in;
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