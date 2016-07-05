#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"
#include "def.h"

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
