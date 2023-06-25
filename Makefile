
# linked_list start
linked_list_app: linked_list_main.o linked_list.o linked_list_test.o utils.o
	gcc -o linked_list_app.out linked_list_main.o linked_list.o linked_list_test.o utils.o

linked_list_main.o: ./src/linked_list_main.c
	gcc -c ./src/linked_list_main.c
	
linked_list.o: ./src/linked_list.c
	gcc -c ./src/linked_list.c

linked_list_test.o: ./src/linked_list_test.c
	gcc -c ./src/linked_list_test.c
# linked_list end

# sequential_list start
sequential_list_app: sequential_list_main.o sequential_list.o utils.o
	gcc -o sequential_list_app.out sequential_list_main.o sequential_list.o utils.o

sequential_list_main.o: ./src/sequential_list_main.c
	gcc -c ./src/sequential_list_main.c
	
sequential_list.o: ./src/sequential_list.c
	gcc -c ./src/sequential_list.c
# sequential_list end

# sequential_stack start - para testes, remove comentário do main.
sequential_stack_app: sequential_stack.o sequential_list.o utils.o
	gcc -o sequential_stack_app.out sequential_stack.o sequential_list.o utils.o

sequential_stack.o: ./src/sequential_stack.c
	gcc -c ./src/sequential_stack.c
# sequential_stack end

# linked_stack start - para testes, remove comentário do main.
linked_list_stack_app: linked_list_stack.o linked_list.o utils.o
	gcc -o linked_list_stack_app.out linked_list_stack.o linked_list.o utils.o

linked_list_stack.o: ./src/linked_list_stack.c
	gcc -c ./src/linked_list_stack.c
# linked_stack end

# others start
utils.o: ./src/utils.c
	gcc -c ./src/utils.c

stack_q3: linked_list_stack.o linked_list.o utils.o
	gcc -c ./src/stack_q3.c && gcc -o stack_q3.out stack_q3.o linked_list_stack.o linked_list.o utils.o

stack_q4: linked_list_stack.o linked_list.o utils.o
	gcc -c ./src/stack_q4.c && gcc -o stack_q4.out stack_q4.o linked_list_stack.o linked_list.o utils.o

stack_q5: linked_list_stack.o linked_list.o utils.o
	gcc -c ./src/stack_q5.c && gcc -o stack_q5.out stack_q5.o linked_list_stack.o linked_list.o utils.o
# others end

clean:
	rm -f *.o *.out
