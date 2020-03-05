#include "service.h"

cell_t** load (int* r, int* c, cell_t** space2, FILE* in) {
    char* str1 = "OK";
    char str[256];
//    fscanf(in, "%s", str);
puts(str1);
    if (!fscanf(in, "COLUMNS = %d\n", c)) *c=10;
printf("c = %d\n", *c);

//    puts(str);
    if (!fscanf(in, "ROWS = %d\n", r)) *r=10;
puts(str1);
printf("r = %d\n", *r);
    *c+=2;
    *r+=2;
    int i, j;
    fscanf(in,"\n");
    cell_t** space = malloc(*r * sizeof(cell_t*));
puts("Malloc OK");
    for (i=0; i<*r; i++){
        space[i] = malloc(*c * sizeof(cell_t));
printf("Malloc #%d OK\n", i); 
    }
    prepare_space(*r,*c,space);
print_space(*r, *c, space, 20000);   
puts(str1);

    for (i=1; i<*r-1; i++) {
        fscanf(in, "%s\n", str);
        puts (str1);
        puts(str);
        for (j=1; j<*c-1; j++) {
printf("str[%d] = %d\n", j-1, str[j-1]-'0');
printf("space[%d][%d].state", i, j); 
printf("space[%d][%d].state = %d", i, j, space[i][j].state); 
        print_space(*r, *c, space, 20000);
printf("space[%d][%d].state = %d", i, j, space[i][j].state); 
        space[i][j].state = str[j-1] - '0';
printf("space[%d][%d].state = %d", i, j, space[i][j].state); 
        }
    }
    return space;
}

//save (int r, int c, cell_t space[r][c], FILE* out) {
//    ;
//}