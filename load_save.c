#include "service.h"

FILE* load_dim(int *r, int *c, FILE *in){
    if (!fscanf(in, "COLUMNS = %d\n", c)) *c=10;
    if (!fscanf(in, "ROWS = %d\n", r)) *r=10;
    *r+=2;
    *c+=2;
    return in;
}