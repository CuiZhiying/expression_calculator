expression: expression_value.o my_stack.o getop.o
	gcc expression_value.o my_stack.o getop.o -o expression -lm

expression_value.o: expression_value.c getop.h my_stack.h def.h
	gcc -c expression_value.c

my_stack.o: my_stack.c my_stack.h def.h
	gcc -c my_stack.c

getop.o: getop.c getop.h def.h
	gcc -c getop.c

clean:
	@echo "cleanning project..."
	-rm *.o
	@echo "clean completed!"
