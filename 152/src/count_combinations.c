/*
 * =====================================================================================
 *
 *       Filename:  count_combinations.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/20 15:23:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"count_combinations.h"
#include<stdlib.h>

#define N_DEBUG 7

uint64_t
count_combinations_recursive
	(double number,
	 uint64_t n_min,
	 uint64_t n_max,
	 double tol,
	 double* sums);

uint64_t
count_combinations
	(double number,
	 uint64_t n_min,
	 uint64_t n_max,
	 double tol)
{
	double *sums = calloc(n_max + 1, sizeof(double));
	sums[0] = 0;
	for(size_t i = 1; i <= n_max; ++i)
	{
		sums[i] = sums[i-1] + (double) 1/ ( (double) i*(double) i);
	}
	for(size_t i = 0; i <= n_max; ++i)
	{
		sums[i] = sums[n_max] - sums[i] ;
		printf("%f\n", sums[i]);
	}
	uint64_t count = count_combinations_recursive(number, n_min, n_max, tol, sums);
	free(sums);
	return count;
}

uint64_t
count_combinations_recursive
	(double number,
	 uint64_t n_min,
	 uint64_t n_max,
	 double tol,
	 double* sums)
{
	if(n_min > n_max)
	{
		return 0;
	}
	if(number > sums[n_min])
	{
		return 0;
	}
	if(number < tol)
	{
		return 1;
		printf("%f %zu %zu\n", number, n_min, n_max);

	}
	uint64_t count = 0;
	double n = n_min;
	if(n_min == N_DEBUG)
	{
		
		printf("count = %zu\n", count);
	}
	if(number > 1/(n*n))
	{
		count += count_combinations_recursive(number - 1/(n*n), n_min + 1, n_max, tol, sums);
	}
	if(n_min == N_DEBUG)
	{
		
		printf("count = %zu\n", count);
	}
	if(number > tol)
	{
		count += count_combinations_recursive(number, n_min + 1, n_max, tol, sums);
	}
	if(n_min == N_DEBUG)
	{
		
		printf("count = %zu\n", count);
	}
	return count;
}
