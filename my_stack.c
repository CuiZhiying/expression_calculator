#include <stdio.h>
#include <stdlib.h>

#define Status int
#define OK     1
#define Error  0
#define Empty  (-1)
#define Overflow (-3)
#define Underflow (-4)

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
        return Error;
    stack->base = (float *)malloc( stack_size * sizeof(float) );
    if( !stack->base )
        return Error;
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

int main()
{
    int i;
    float elem;
    Stack *stack = create_stack(100);
    for( i = 0; i < 10; i++ ){
        printf("%d\n", i);
        if(push(stack, (float)i) == Error)
        {
                printf("pushed %d\n", i);
                break;
        }
    }
    printf("push finished!\n");
    for( i = 0; i < 10; i++ ){
        if(pop(stack, &elem )==Error)
            break;
        printf("%0.2f\t", elem );
    }
    printf("\n");
    return 0;
}


