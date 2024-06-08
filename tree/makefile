tree.o: tree.h tree.c
	    gcc -c tree.c

tree_tests: tree.o tree_test.c
	gcc -o tree_test tree_test.c ../file/file.c tree.o -I/usr/local/include/unity -L/usr/local/lib -lunity
	./tree_test