
# linked_list start
linked_list_app: linked_list_main.o linked_list.o linked_list_test.o
	gcc -o linked_list_app.out linked_list_main.o linked_list.o linked_list_test.o

linked_list_main.o: ./src/linked_list_main.c
	gcc -c ./src/linked_list_main.c
	
linked_list.o: ./src/linked_list.c
	gcc -c ./src/linked_list.c

linked_list_test.o: ./src/linked_list_test.c
	gcc -c ./src/linked_list_test.c
# linked_list end

# sequential_list start
sequential_list_app: sequential_list_main.o sequential_list.o
	gcc -o sequential_list_app.out sequential_list_main.o sequential_list.o

sequential_list_main.o: ./src/sequential_list_main.c
	gcc -c ./src/sequential_list_main.c
	
sequential_list.o: ./src/sequential_list.c
	gcc -c ./src/sequential_list.c
# sequential_list end

clean:
	rm -f *.o *.out
