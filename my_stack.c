#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"
#include "def.h"

/*
#define Status int
#define OK     1
#define Error  0
#define Empty  (-1)
#define Overflow (-3)
#define Underflow (-4)
*/

typedef struct Stack
{
    float *base;
    int   top;               //指向栈顶元素而非栈顶的第一个空元素
    int   stack_size;
}Stack;

Stack * create_stack( int stack_size )
{
    Stack * stack = ( Stack * )malloc( sizeof(Stack) );
    if( !stack )
        return NULL;
    stack->base = (float *)malloc( stack_size * sizeof(float) );
    if( !stack->base ){
	free(stack);
	stack = NULL;
        return NULL;
    }
    stack->top = Empty;
    stack->stack_size = stack_size;
    return stack;
}

Status pop( Stack *stack, float *elem )
{
    if( stack->top == Empty )
        return Empty;
    *elem = stack->base[(stack->top)--];
    return OK;
}

Status push( Stack *stack, float elem )
{
    if( stack->top >= ( stack->stack_size - 1) )
        return Overflow;
    stack->base[++stack->top] = elem;
    return OK;
}

Status print_stack_num( Stack *stack )
{
    int i;
    printf("(Stack base)\t");
    if( stack == NULL || stack->top == Empty )
        printf("NULL\t");
    else for( i = 0; i <= stack->top; i++ )
        printf("%0.4f\t", stack->base[i]);
    printf("(Stack top)\n");
    return OK;
}

Status print_stack_char( Stack *stack )
{
    int i;
    printf("(Stack base)\t");
    if( stack == NULL || stack->top == Empty )
        printf("NULL\t");
    else for( i = 0; i < stack->top; i++ )
        printf("%c\t", (char)stack->base[i]); 
    printf("(Stack top)\n");
    return OK;
}

/*
int main()
{
    int i;
    float elem;
    Stack *stack = create_stack(100);
    for( i = 0; i < 100; i++ ){
        printf("%d\n", i);
        if(push(stack, (float)i) == Error)
        {
                printf("pushed %d\n", i);
                break;
        }
    }
    print_stack_char( stack );
    print_stack_num( stack );
    printf("push finished!\n");
    for( i = 0; i < 100; i++ ){
        if(pop(stack, &elem )==Error)
            break;
        printf("%0.2f\t", elem );
    }
    print_stack_char( stack );
    print_stack_num( stack );
    printf("\n");
    return 0;
}

*/
