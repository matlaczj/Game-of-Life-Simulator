#include "service.h"

int count_friends(int r, int c, cell_t space[r][c], int i, int j) 
{
    //takes indexes of element in space 
    //and counts neighbours that are not padding and ON
    int count = 0;
    
    if( (space[i]+j-1) -> is_padding == 0 && (space[i]+j-1) -> state == ON ) 
        count++;
    if( (space[i]+j+1) -> is_padding == 0 && (space[i]+j+1) -> state == ON ) 
        count++;
    if( (space[i-1]+j) -> is_padding == 0 && (space[i-1]+j) -> state == ON ) 
        count++;
    if( (space[i+1]+j) -> is_padding == 0 && (space[i+1]+j) -> state == ON ) 
        count++;
    if( (space[i-1]+j-1) -> is_padding == 0 && (space[i-1]+j-1) -> state == ON ) 
        count++;
    if( (space[i-1]+j+1) -> is_padding == 0 && (space[i-1]+j+1) -> state == ON ) 
        count++;
    if( (space[i+1]+j-1) -> is_padding == 0 && (space[i+1]+j-1) -> state == ON ) 
        count++;
    if( (space[i+1]+j+1) -> is_padding == 0 && (space[i+1]+j+1) -> state == ON ) 
        count++;
    
    return count;
    
}