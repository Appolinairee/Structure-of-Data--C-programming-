file.o: file.h file.c
	    gcc -c file.c

file_tests: file.o file_test.c
	gcc -o file_test file_test.c file.o -I/usr/local/include/unity -L/usr/local/lib -lunity
	./file_test