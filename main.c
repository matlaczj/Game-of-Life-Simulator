#include "service.h"

#define DEBUG //... bardzo przydatne, jak robisz debugi to dawaj w ifdefy :>
/*Time between changes of printed state in microseconds (1 000 000 is 1 second, 1 000 is 1 milisecond)*/
#define WAIT 100000 //1/10 sec

int main(int argc, char* argv[])
{
    /* W tej wersji programu pierwszy argument to nazwa pliku LIFE, z ktorego zostanie wczytany stan poczatkowy.
    If user wanted to create the biggest square possible that would be of size 1669x1669, but the biggest
    square that fits my 11-inch screen is 400x400 cells.
    -- oof, *cries in 4K*
    Maximum of 2 875 561 cells can be simulated at once so r times c cant be bigger than 
    this number or a segmentation fault will appear. 
    Later we have to add 2 to r and to c to make space for padding (frame) for space which we will need.*/
    int r, c;
    FILE* in = argc > 1 ? fopen(argv[1], "r") : NULL;
    if(argc > 1 && in!=NULL)
        in = load_dim(&r,&c,in);
    else
        r = c = 12;

    if(r*c > 1671*1671)
    {
        printf("\n%s:Too many cells. Maximum amount of cells is %d.\n",argv[0],1671*1671);
        return -1;
    }
    
    /*A 2D matrix is created. Its the most important thing in this program. The following function call
    fills matrix with appropriate values.*/
    cell_t space[r][c];
    prepare_space(r,c,space);
    
//    if (argc > 1 && in!=NULL)
//        load(r,c,space,in);
//    else {
    /*Here we create the starting state of this automata.*/
        int i,j;
            for(i=1; i<r-1; i+=5)
                for(j=1; j<c-1; j+=5)
                    glider(r,c,space,i,j);
//    }

#ifdef DEBUG
    FILE* out = fopen("out.png", "wb");
    if (!out)
        printf("\n%s: File %s could not be opened for writing", argv[0], "out.png");
    print_png(r, c, space, out);
    fclose (out);
#endif
 
    /*Main loop in the program. 
    Executes maximum of times equal to the 3rd argument.
    4th and higher arguments are the states to save into png files without repeats and ascending.
    'name' is an array used to create a name for png file following this scheme: "number_of_generation.png".
    Inside the while loop we go through each cell in space matrix except for padding. We check if the conditions for
    birth, survival or death for each cell are met and if so we save the new state into next_state variable.
    Then 'print_update_space' funtion prints current state and updates states state = next_state.
    Later we increment nrgens to indicate the current generation which are counted from 0th generation. 
    */
    char name[30];
    const int gencount = argc > 2 ? atoi(argv[2]) : 100;
    int k = 4;
    int running = 1;
    int nrgens = gencount;

    while(nrgens-- && running) // chcesz to mozesz usunac to running, mysle ze jednak jest przydatne :p
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

        mkdir("output_images", 0777);
        sprintf(name,"output_images/gen%d.png", gencount-nrgens);
        FILE* gen = fopen(name, "wb");

#ifdef DEBUG
        if (!gen)
            printf("\n%s: File %s could not be opened for writing", argv[0], name);
#endif
        print_png(r,c,space,gen);
        fclose(gen);

            /*tutaj funkcja ktora bedzie zapisywac do pliku png, przykladowy 
            generator nazw: sprintf(name,"%d%s",nrgens,".png"); */

        update_space(r,c,space);
        print_space(r,c,space, WAIT);
    }
}
