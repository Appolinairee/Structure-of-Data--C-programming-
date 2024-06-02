list.o: list.h list.c
	    gcc -c list.c

tests: list.o list_test.c
	gcc -o list_test list_test.c list.o -I/usr/local/include/unity -L/usr/local/lib -lunity
	./list_test