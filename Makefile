exec: main.o prepare_space.o update_space.o print_space.o count_friends.o life_cycle.o toys.o print_png.o
	cc -o exec main.o prepare_space.o update_space.o print_space.o count_friends.o life_cycle.o toys.o print_png.o -lpng 
    
main.o: main.c service.h
	cc -c main.c
    
prepare_space.o: prepare_space.c service.h
	cc -c prepare_space.c
    
update_space.o: update_space.c service.h
	cc -c update_space.c

print_space.o: print_space.c service.h
	cc -c print_space.c
    
count_friends.o: count_friends.c service.h
	cc -c count_friends.c
    
life_cycle.o: life_cycle.c count_friends.c service.h
	cc -c life_cycle.c
    
toys.o: toys.c service.h
	cc -c toys.c

print_png.o: print_png.c service.h
	cc -c print_png.c
    
clean:
	rm *.o 
