test: $(n)
	./$(n).out > f$(n).test.out && diff f$(n).test.out ./tests/f$(n).test

$(n): f$(n).o bst.o
	gcc -o $(n).out f$(n).o bst.o

test_$(n): $(n)
	./$(n).out > f$(n).test.out && diff f$(n).test.out ./tests/f$(n).test

f$(n).o: f$(n).c
	gcc -c f$(n).c

2: f2.o bst.o
	gcc -o 2.out f2.o bst.o

test_2: 2
	./2.out > f2.test.out && diff f2.test.out ./tests/f2.test

f2.o: f2.c
	gcc -c f2.c

3: f3.o bst.o
	gcc -o 3.out f3.o bst.o

test_3: 3
	./3.out > f3.test.out && diff f3.test.out ./tests/f3.test

f3.o: f3.c
	gcc -c f3.c

4: f4.o bst.o
	gcc -o 4.out f4.o bst.o

test_4: 4
	./4.out > f4.test.out && diff f4.test.out ./tests/f4.test

f4.o: f4.c
	gcc -c f4.c

bst.o: bst.c
	gcc -c bst.c

clean:
	rm -f *.o *.out