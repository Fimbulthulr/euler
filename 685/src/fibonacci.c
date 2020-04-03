/*
 * =====================================================================================
 *
 *       Filename:  fibonacci.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/20 05:57:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"fibonacci.h"
#include<stdlib.h>
#include<stdio.h>


void
fibonacci
	(size_t n,
	 uint64_t *fib)
{
	fib[0] = 0;
	fib[1] = 1;
	for(size_t i = 2; i < n; ++i)
	{
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] > UINT64_MAX/2)
		{
			fprintf(stderr, "ERROR: fibonacci number %zu is too large\n", i);
		}
	}
}
