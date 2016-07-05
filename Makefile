test: test.o my_stack.o
	gcc test.o my_stack.o -o test

test.o: test.c my_stack.h def.h
	gcc -c test.c

my_stack.o: my_stack.c my_stack.h def.h
	gcc -c my_stack.c

clean:
	@echo "cleanning project..."
	-rm *.o
	@echo "clean completed!"
