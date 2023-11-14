f$(n): f$(n).o bst.o
	gcc -o $(n).out f$(n).o bst.o

test: $(n)
	./$(n).out > f$(n).test.out && diff f$(n).test.out ./tests/f$(n).test

f$(n).o: f$(n).c
	gcc -c f$(n).c

bst.o: bst.c
	gcc -c bst.c

clean:
	rm -f *.o *.out