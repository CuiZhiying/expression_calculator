/*
 * =====================================================================================
 *
 *       Filename:  getop.c
 *
 *    Description:  参考C程序设计语言中的获取数据或者字符的函数
 *
 *        Version:  1.0
 *        Created:  07/04/2016 09:40:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  叶孤城 (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "getop.h"
#include "def.h"

/*
#define BUFSIZE 100
#define NUMBER 0
*/

char buf[BUFSIZE];//使用一个栈来作为缓冲
int bufp = 0;

int getch( void )
{
	return (bufp > 0) ? buf[ --bufp ] : getchar();
}

void ungetch( int c )
{
	if( bufp >= BUFSIZE )
		printf( "ungetch: too many characters\n");
	else
		buf[ bufp++ ] = c;
}


int getop( char str[], int flag ) // 将获取到的数字数组串放入到str中,flag用来标志前一个返回的是数字还是运算符
{
	int i, ch;
	
	while ( (str[0] = ch = getch() ) == ' ' || ch == '\t' )
		;
	if( flag && ( ch == '+' || ch == '-') ){      //如果前一个取到的是运算符并且下一是数字
		if( !isdigit( ch = getch()) ){
			ungetch( ch );
			return str[0];
		}
	}else
		str[0] = '+';
	str[1] = ch;
	str[2] = '\0';
	if( !isdigit( ch ) && ch != '.' )
		return ch;                       //不是数字，是操作符，直接返回操作符
	i = 1;
	if ( isdigit( ch ) )
		while( isdigit( str[++i] = ch = getch() ) )  //以字符串的形式收集整数部分
			;
	if ( ch == '.' )
		while( isdigit( str[++i] = ch = getch() ) )  //收集小数部分
			;
	str[i] = '\0';
	if( ch != EOF )
		ungetch(ch);
	return NUMBER;
}


/*
int main()
{
	int type;
	char str[100];
	int  flag = 1;
	while( (type = getop(str, flag) ) != EOF ){
		if( type == NUMBER ){
//			printf("%c\n", str[0]);
			printf("%s\t%0.2f\n", str, atof(str) );
			flag = 0;
//			printf(" %f\n", atof(str) );
		}else {
			putchar( type );
			putchar( '\n' );
			flag = 1;
		}
	}
	return 0;
}

*/



