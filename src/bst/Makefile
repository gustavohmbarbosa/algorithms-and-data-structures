all:
	make test f=1 && make test f=2 && make test f=3 && make test f=4 && make test f=5 && make test f=7 && make test f=8 && make test f=9 && make test f=10 && make test f=11 && make test f=13

main: main.o bst.o
	gcc -o main.bin main.o bst.o

test: file
	diff f$(f).test.out ./tests/f$(f).out

file: main
	./main.bin < ./tests/f$(f).in -lh > f$(f).test.out 

main.o: main.c
	gcc -c main.c

bst.o: bst.c
	gcc -c $<

clean:
	rm -f *.o *.out *.bin