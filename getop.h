/*
 * =====================================================================================
 *
 *       Filename:  getop.h
 *
 *    Description:  head file for getop.c
 *
 *        Version:  1.0
 *        Created:  07/05/2016 10:11:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  叶孤城 (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GETOP_H_
#define GETOP_H_

int getch( void );
void ungetch( int c );
int getop( char str[], int flag ); // 将获取到的数字数组串放入到str中,flag用来标志前一个返回的是数字还是运算符

#endif
