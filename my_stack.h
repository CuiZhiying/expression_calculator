/*
 * =====================================================================================
 *
 *       Filename:  my_stack.h
 *
 *    Description:  head file for  my_stack.c
 *
 *        Version:  1.0
 *        Created:  07/05/2016 09:54:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  叶孤城 (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef MY_STACK_H_
#define MY_STACK_H_

#include "def.h"

//struct Stack;
//typedef struct Stack Stack;

typedef struct Stack
{
    float *base;
    int   top;               //Ö¸ÏòÕ»¶¥ÔªËØ¶ø·ÇÕ»¶¥µÄµÚÒ»¸ö¿ÕÔªËØ
    int   stack_size;
}Stack;


Stack * create_stack( int stack_size );
Status pop( Stack *stack, float *elem );
Status push( Stack *stack, float elem );
//Status push( Stack *stack, float elem );
Status print_stack_num( Stack *stack );
Status print_stack_char( Stack *stack );
int stack_top( Stack *stack );
Status reset_stack( Stack *stack );
Status stack_is_empty( Stack *stack );
#endif
