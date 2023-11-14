all: f1 f2 f3 f4 f5

f%: f%.o bst.o
	gcc -o $@.out $< bst.o

test: f$(n)
	./$<.out > $<.test.out && diff $<.test.out ./tests/$<.test

f%.o: f%.c
	gcc -c $<

bst.o: bst.c
	gcc -c $<

clean:
	rm -f *.o *.out