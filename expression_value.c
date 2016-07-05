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


int main()
{
	int type;
	double operator;
	char s[BUFSIZE];
	int loop = 1;

	Stack * operation = create_stack( 100 );
	Stack * numbers   = create_stack( 100 ); 

	while( loop ){
		while ( ( type = getop(s) ) != EOF ){
			switch (type){
			case NUMBER: 
				push( numbers, atof(s) );
				break;
			case ’+‘
			}
		}
	}
	return 0;
}



















