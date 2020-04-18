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
#include<stdio.h>

#define N_PROGRESS 16
uint64_t progress;

uint64_t
count_combinations_recursive
	(uint64_t n,
	 mpq_t z,
	 mpq_t *sums);

uint64_t
count_combinations
	(mpq_t z,
	 uint64_t n_min,
	 uint64_t n_max)
{
	mpq_t *sums = calloc(n_max + 2, sizeof(mpq_t));
	for(size_t i = 0; i < n_max + 2; ++i)
	{
		mpq_init(sums[i]);
	}
	
	for(size_t i = 1; i <= n_max; ++i)
	{
		mpq_set_ui(sums[i], 1, i*i);
		mpq_add(sums[i], sums[i], sums[i-1]);
	}
	mpq_set(sums[n_max + 1], sums[n_max]);

	for ( size_t i = n_max; i ; --i ) {
		mpq_sub(sums[i], sums[n_max + 1], sums[i-1]);
	}
	mpq_set_ui(sums[n_max + 1], 0, 1);
	progress = 0;
	uint64_t count = count_combinations_recursive(n_min, z, sums);	
	for(size_t i = 0; i < n_max+2; ++i)
	{
		mpq_clear(sums[i]);
	}
	free(sums);
	return count;
}

uint64_t
count_combinations_recursive
	(uint64_t n,
	 mpq_t z,
	 mpq_t *sums)
{
	if(n == N_PROGRESS)
	{
		printf("progress: %f%%\n", 100*(double) (progress++) / ( (double) (1<< (N_PROGRESS-2))));
	}
	mpq_set_ui(sums[0], 0, 1);
	if(mpq_equal(sums[0], z))			//has reached a sum, end
	{
		return 1;
	}
	if(mpq_cmp(z, sums[n]) > 0)			//can no longer complete the sum, cut recursion -> also at max depth
	{
		return 0;
	}
	uint64_t count = 0;
	count += count_combinations_recursive(n+1, z, sums);

	mpq_set_ui(sums[0], 1, n*n);
	if(mpq_cmp(z, sums[0]) >= 0)
	{
		mpq_sub(z, z, sums[0]);			//decrement z for second subtree
		count += count_combinations_recursive(n+1, z, sums);
		mpq_set_ui(sums[0], 1, n*n);	//reset z to preserve value
		mpq_add(z, z, sums[0]);
	}
	return count;
}
