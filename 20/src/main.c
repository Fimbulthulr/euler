/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/20 00:19:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), gx231@stud.uni-heidelberg.de
 *   Organization:  Universität Heidelberg
 *
 * =====================================================================================
 */

#include"segmented_factorial.h"
#include<stdio.h>
#include<stdlib.h>

#define SEGMENTS 20
#define CUTOFF_POWER 10
#define N 100
int
main
	(int argc, 
	 char** argv)	
{
	uint64_t segments[SEGMENTS];
	uint64_t cutoff = 1;
	for(uint64_t i = 0; i < CUTOFF_POWER; ++i)
	{
		cutoff *= 10;
	}
	uint64_t n = N;

	if(argc > 1)
	{
		n = atoi(argv[1]);
	}
	segmented_factorial(n, cutoff, SEGMENTS, segments);
	uint64_t c = 0;
	for(size_t i = 0; i < SEGMENTS; ++i)
	{
		for(; segments[i]; segments[i] /= 10)
		{
			c += segments[i] % 10;
		}
	}
	printf("%zu! has a digit sum of %zu\n", n, c);
}


