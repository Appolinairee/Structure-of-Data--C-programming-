bulle.o: bulle.h bulle.c
	    gcc -c bulle.c

tests: bulle.o bulle_test.c
	gcc -o bulle_test bulle_test.c bulle.o -I/usr/local/include/unity -L/usr/local/lib -lunity
	./bulle_test