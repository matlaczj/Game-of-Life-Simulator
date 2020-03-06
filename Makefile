CC := cc -ggdb #usun to ggdb jesli nie uzywasz valgrinda, whatever

exec: main.o prepare_space.o update_space.o print_space.o count_friends.o life_cycle.o toys.o print_png.o
	$(CC) -o exec main.o prepare_space.o update_space.o print_space.o count_friends.o life_cycle.o toys.o print_png.o -lpng 
    
main.o: main.c service.h
	$(CC) -c main.c
    
prepare_space.o: prepare_space.c service.h
	$(CC) -c prepare_space.c
    
update_space.o: update_space.c service.h
	$(CC) -c update_space.c

print_space.o: print_space.c service.h
	$(CC) -c print_space.c
    
count_friends.o: count_friends.c service.h
	$(CC) -c count_friends.c
    
life_cycle.o: life_cycle.c count_friends.c service.h
	$(CC) -c life_cycle.c
    
toys.o: toys.c service.h
	$(CC) -c toys.c

print_png.o: print_png.c service.h
	$(CC) -c print_png.c
    
clean:
	rm *.o 
