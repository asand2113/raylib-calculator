calc: main.o button.o
	gcc main.o button.o -lraylib -o calc

main.o: main.c
	gcc -Wall -Werror main.c -c -lraylib
	
button.o: button.c
	gcc -Wall -Werror button.c -c -lraylib
	
clean:
	rm -f calc main.o button.o