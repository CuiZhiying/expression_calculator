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
/*
#define Status    int
#define OK        1
#define Error     0
#define Empty     (-1)
#define Underflow (-2)
#define Overflow  2
*/

typedef struct Stack{} Stack;

Stack * create_stack( int stack_size );
Status pop( Stack *stack, float *elem );
Status push( Stack *stack, float elem );
Status push( Stack *stack, float elem );
Status print_stack_num( Stack *stack );
Status print_stack_char( Stack *stack );

#endif
