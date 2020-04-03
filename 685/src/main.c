/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/20 06:03:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

#include"fibonacci.h"
#include"inv_digit_sum.h"

#define N 90
#define p 1000000007
int
main
	(int argc,
	 char **argv)
{
	int n = N;
	if(argc > 1)
	{
		n = atoi(argv[1]);
	}
	uint64_t *fib = calloc(n+1, sizeof(uint64_t));
	fibonacci(n+1, fib);
	uint64_t sum = 0;
	
		for(size_t i = 2; i < n+1; ++i)
		{
			printf("status: f(%2zu) = %19" PRIu64"\n", i, fib[i]);
			uint64_t tmp= inv_digit_sum(fib[i]);
			sum += tmp;
			sum %= p;
			printf("%" PRIu64 "\n\n", tmp);
		}
	
	printf("\n%" PRIu64 "\n", sum);
	 
	printf("\n%" PRIu64 "\n", inv_digit_sum(20));
}
