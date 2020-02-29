exec: main.o prepare_space.o print_space.o count_friends.o update_states.o life_cycle.o toys.o
	cc -o exec main.o prepare_space.o print_space.o count_friends.o update_states.o life_cycle.o toys.o 
    
main.o: main.c service.h
	cc -c main.c
    
prepare_space.o: prepare_space.c service.h
	cc -c prepare_space.c
    
print_space.o: print_space.c service.h
	cc -c print_space.c
    
count_friends.o: count_friends.c service.h
	cc -c count_friends.c
    
update_states.o: update_states.c service.h
	cc -c update_states.c
    
life_cycle.o: life_cycle.c count_friends.c service.h
	cc -c life_cycle.c
    
toys.o: toys.c service.h
	cc -c toys.c
    
clean:
	rm *.o 
