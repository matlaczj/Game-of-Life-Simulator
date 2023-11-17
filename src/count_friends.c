#include "service.h"

/*Takes the indexes of cell's position. Checks all 8 neighbouring cells.
If that cell is not padding and is alive count variable is incremented.*/
int count_friends(int r, int c, cell_t space[r][c], int i, int j) 
{
    int count = 0;
    
    if( (space[i]+j-1) -> is_padding == IRR && (space[i]+j-1) -> state == ON ) 
        count++;
    if( (space[i]+j+1) -> is_padding == IRR && (space[i]+j+1) -> state == ON ) 
        count++;
    if( (space[i-1]+j) -> is_padding == IRR && (space[i-1]+j) -> state == ON ) 
        count++;
    if( (space[i+1]+j) -> is_padding == IRR && (space[i+1]+j) -> state == ON ) 
        count++;
    if( (space[i-1]+j-1) -> is_padding == IRR && (space[i-1]+j-1) -> state == ON ) 
        count++;
    if( (space[i-1]+j+1) -> is_padding == IRR && (space[i-1]+j+1) -> state == ON ) 
        count++;
    if( (space[i+1]+j-1) -> is_padding == IRR && (space[i+1]+j-1) -> state == ON ) 
        count++;
    if( (space[i+1]+j+1) -> is_padding == IRR && (space[i+1]+j+1) -> state == ON ) 
        count++;
    
    return count;
}