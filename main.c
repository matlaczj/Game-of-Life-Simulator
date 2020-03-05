#include "service.h"
#define DEBUG   //do usuniecia

#define WAIT 200000 //for the animation speed, the bigger the slower the animation is

int main(int argc, char* argv[])
{
    int r = 0;
    int c = 0;
    scanf("%d %d",&r,&c);
    // user gives rows and columns needed but we have to add 2 rows and 2 columns for padding
    r+=2;
    c+=2;
    
    cell_t space[r][c];
    prepare_space(r,c,space);
    
    //creating a glider for testing:
    //of size 3x3 so r and c should be at least 3 long
    //please remeber that indexes shouldnt be on padding
    if(glider(r,c,space,1,1)==0) 
    {
        printf("\n%s: too little space or wrong starting position for object\n",argv[0]);
        return -1;
    }
    FILE* in = fopen("out.png", "wb");
    if (!in)
        printf("\n%s: File %s could not be opened for writing", argv[0], "out.png");
    update_space(r,c,space);
    print_space(r,c,space, WAIT);
    print_png(r, c, space, in);

    fclose(in);
    
    int running = 1; 
    //running is incremented if at least 1 cell is still present on the space 
    //meaning it was born or survived, this way we know its still worth running the program 
    //because there is potential for new things to happen
    
    //ee, zamiast tego bym mierzył birth i death (survival moze się dziać na statycznej planszy
    //w nieskończoność...)
    int nrgens = 100; //number of generations to execute and print
    while(nrgens-- && running)
    {
        running = 0;
        int i,j;
        for(i=1; i<r-1; i++)
            for(j=1; j<c-1; j++)
            {
                if(birth(r,c,space,i,j)) running++;
                else if(death(r,c,space,i,j)) running++;     //dodałem else bo tylko jedna opcja moze byc
                else survival(r,c,space,i,j);
            }
        update_space(r,c,space);
        print_space(r,c,space, WAIT);
    }
}
