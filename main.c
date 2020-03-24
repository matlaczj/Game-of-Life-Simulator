#include "service.h"

//#define DEBUG //... bardzo przydatne, jak robisz debugi to dawaj w ifdefy :> //odkomentuj, jesli zobaczysz bledy
/*Time between changes of printed state in microseconds (1 000 000 is 1 second, 1 000 is 1 milisecond)*/

int main(int argc, char *argv[])
//Wywolanie: ./exec plik_startowy.life liczba_generacji [szybkosc_wyswietlania] [custom_name] [numer_generacji1] [numer_generacji2] ...
//Trzeci argument to liczba calkowita. 0 - brak wyswietlania, 10 - wartosc domyslna.
//Jesli czwarty jest okreslony, wygenerowane pliki LIFE i PNG
//beda zaczynaly sie od custom_name i zostana przeniesione do osobnego folderu.
//Jesli piaty jest okreslony, zostana wygenerowane pliki PNG i LIFE tylko okreslonych generacji.
//
//Przyklady uzycia:
// ./exec example.life 20 0 liczby_pierwsze 2 3 5 7 11 13 17 19
// (pierwszy przyklad nic nie wyswietli, tylko wygeneruje pliki :))
// ./exec gliders.life 100 5
// ./exec example.life 200 50
{
    /* W tej wersji programu pierwszy argument to nazwa pliku LIFE, z ktorego zostanie wczytany stan poczatkowy.
    If user wanted to create the biggest square possible that would be of size 1669x1669, but the biggest
    square that fits my 11-inch screen is 400x400 cells.
    -- oof, *cries in 4K*
    Maximum of 2 875 561 cells can be simulated at once so r times c cant be bigger than 
    this number or a segmentation fault will appear. 
    Later we have to add 2 to r and to c to make space for padding (frame) for space which we will need.*/
    int r, c;
    FILE *in = argc > 1 ? fopen(argv[1], "r") : NULL;
    if (argc > 1 && in != NULL)
        load_dim(&r, &c, in); //in = load_dim(&r,&c,in); // nie ma sensu przypisywac in jego wlasnej wartosci
    else
        r = c = DEF_SQ_SIDE + 2; //zastapilem magiczna liczbe 10+2=12 makrem aby byla wieksza plastycznosc

    if (r * c > 1671 * 1671)
    {
        printf("\n%s:Too many cells. Maximum amount of cells is %d.\n", argv[0], 1671 * 1671);
        return -1;
    }

    /*A 2D matrix is created. Its the most important thing in this program. The following function call
    fills matrix with appropriate values.*/
    cell_t space[r][c];
    prepare_space(r, c, space);

    if (argc > 1 && in != NULL)
        load(r, c, space, in);
    else
    {
        /*Here we create the starting state of this automata.*/
        int i, j;
        for (i = 1; i < r - 1; i += 5)
            for (j = 1; j < c - 1; j += 5)
                glider(r, c, space, i, j);
    }

    /*Main loop in the program. 
    Executes maximum of times equal to the 3rd argument.
    4th and higher arguments are the states to save into png files without repeats and ascending.
    'name' is an array used to create a name for png file following this scheme: "number_of_generation.png".
    Inside the while loop we go through each cell in space matrix except for padding. We check if the conditions for
    birth, survival or death for each cell are met and if so we save the new state into next_state variable.
    Then 'print_update_space' funtion prints current state and updates states state = next_state.
    Later we increment nrgens to indicate the current generation which are counted from 0th generation. 
    */
    char name[64];
    const int gencount = argc > 2 ? atoi(argv[2]) : DEF_N_GENS; //zamieniam magiczna liczbe makrem
    int running = 1;
    int nrgens = gencount;

    int WAIT = 100000;
    if (argc <= 3 || atoi(argv[3]) != 0)
    {
        WAIT = argc > 3 ? 1000000 / atoi(argv[3]) : 100000; //1/10 sec by default
        print_space(r, c, space, WAIT);
    }

    if (argc > 4)
    {
        mkdir(argv[4], 0777);
        sprintf(name, "%s/output_images", argv[4]);
        mkdir(name, 0777);
        sprintf(name, "%s/output_states", argv[4]);
        mkdir(name, 0777);
    }
    else
    {
        mkdir("output_images", 0777);
        mkdir("output_states", 0777);
    }

    int is_saved = 0; //czy aktualna generacja ma byc zapisana

    while (nrgens-- && running) // chcesz to mozesz usunac to running, mysle ze jednak jest przydatne :p
    {
        running = 0;
        int i, j;
        for (i = 1; i < r - 1; i++)
            for (j = 1; j < c - 1; j++)
            {
                if (birth(r, c, space, i, j))
                    running++;
                else if (death(r, c, space, i, j))
                    running++; //dodałem else bo tylko jedna opcja moze byc
                else
                    survival(r, c, space, i, j);
            }

        if (argc > 5)
            for (int k = 5; k < argc; k++)
            {
                if (atoi(argv[k]) == gencount - nrgens)
                {
                    is_saved = 1;
                    break;
                }
                else
                    is_saved = 0;
                
            }
        else
            is_saved = 1;

        if (is_saved)
        {
            if (argc > 4)
                sprintf(name, "%s/output_images/%s%d.png", argv[4], argv[4], gencount - nrgens);
            else
                sprintf(name, "output_images/gen%d.png", gencount - nrgens);
            FILE *gen = fopen(name, "wb");

#ifdef DEBUG
            if (!gen)
                printf("\n%s: File %s could not be opened for writing", argv[0], name);
#endif
            print_png(r, c, space, gen);
            fclose(gen);

            if (argc > 4)
                sprintf(name, "%s/output_states/%s%d.life", argv[4], argv[4], gencount - nrgens);
            else
                sprintf(name, "output_states/gen%d.life", gencount - nrgens);

            gen = fopen(name, "w");

#ifdef DEBUG
            if (!gen)
                printf("\n%s: File %s could not be opened for writing", argv[0], name);
            else
                puts("fopen OK");
#endif
            save(r, c, space, gen);
            fclose(gen);
        }

        update_space(r, c, space);
        if (argc <= 3 || atoi(argv[3]) != 0)
            print_space(r, c, space, WAIT);
    }
}
