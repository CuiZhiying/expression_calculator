/*
 * =====================================================================================
 *
 *       Filename:  expression_value.c
 *
 *    Description:  表达式求值，栈结构和解析数据的函数已经就位
 *
 *        Version:  1.0
 *        Created:  07/05/2016 03:38:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  叶孤城 (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"
#include "getop.h"
#include "def.h"


float operate( double number1, int op, double number2 );
int deal_char( Stack *operation, Stack *number, int type );
int compare( char op1, char op2 );

char table[][7] = 
{
	/*运算符之间的优先级制作成一张表格*/  
        {'>','>','<','<','<','>','>'},  
        {'>','>','<','<','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'<','<','<','<','<','=','0'},  
        {'>','>','>','>','0','>','>'},  
        {'<','<','<','<','<','0','='} 
};

int deal_char( Stack *operation, Stack *number, int type )
{
	float op;
	float number1, number2;
	float reslut;
	int flag;
	int top;
	//printf("%d\n", operation->top);
	if( (top = stack_top( operation )) == -1 )
		return -1;
	if( !(flag = compare( top, type )) )
		return -2;

	switch( flag ){
		case '<':
			push( operation, type);
			return 1;
			break;
		case '>':
			pop( operation, &op );
			pop( number, &number2 );
			pop( number, &number1 );
			push( number, operate( number1, (int)op, number2 ) );
			deal_char( operation, number, type );
			return 1;
			break;
		case '=':
			pop( operation, &op );
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

float operate( double number1, int op, double number2 )
{
	switch( op ){
		case '+': return number1 + number2;
		case '-': return number1 - number2;
		case '*': return number1 * number2;
		case '/': if( number2 )
				return number1 / number2;
			  else{
				printf("Operating error: 除数不能为0！\n");
				return 99.9999;
			  }
		default:
			printf("Operating error: undefined operation!\n");
				return 99.9999;
	}
}

int compare( char op1, char op2 )
{
	int i, j;
	switch ( op1 ){
		case '+': i = 0; break;
		case '-': i = 1; break;
		case '*': i = 2; break;
		case '/': i = 3; break;
		case '(': i = 4; break;
		case ')': i = 5; break;
		case '=': i = 6; break;
		default:
			return 0;
	}
	switch ( op2 ){
                case '+': j = 0; break;
                case '-': j = 1; break;
                case '*': j = 2; break;
                case '/': j = 3; break;
                case '(': j = 4; break;
                case ')': j = 5; break;
                case '=': j = 6; break;
		default:
			return 0;
	}
	return table[i][j];
}

int main()
{
	int type;
	float op;
	float operator;
	char s[BUFSIZE];
	int loop = 1;
	int flag;

	Stack * operation = create_stack( 100 );
	Stack * number    = create_stack( 100 ); 
	
	while( loop ){
		flag = 1;
		push( operation, '=' );
		while ( ( type = getop(s, flag ) ) != EOF ){
                        print_stack_char( operation );
                        print_stack_num( number );			
			switch (type){
			case NUMBER: 
				push( number, atof(s) );
				//printf("\t%f\t", atof(s) );
				flag = 0;
				break;
			case '\n':
			//case '=' :
				pop( number, &op );
				printf("%f\n", op );
				push( operation, '=' );
				flag = 1;
				break;
			default:
				//printf("\t%c\t", type);
				deal_char( operation, number, type );
				flag = 1;
				break;
			}
		}
	}
	return 0;
}

























