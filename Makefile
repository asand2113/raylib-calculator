calc: button.o main.o
	gcc button.o main.o -lraylib -o calc

button.o: button.c
	gcc -Wall -Werror button.c -c -lraylib

main.o: main.c
	gcc -Wall -Werror main.c -c -lraylib
	
clean:
	rm -f calc main.o button.o