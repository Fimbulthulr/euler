/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/20 15:36:25
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
#include"count_combinations.h"

#define N 80
#define TOL 1e-13
int
main
	(int argc,
	 char **argv)
{
	if(argc > 2)
	{
		printf("Usage: %s [N]\n", argv[0]);
	}
	uint64_t n = N;
	if(argc == 2)
	{
		n = atoi(argv[1]);
	}

	mpq_t z;
	mpq_init(z);
	mpq_set_ui(z, 1, 2);
	uint64_t comb = count_combinations(z, 2, n);
	mpq_clear(z);

	printf("There are %" PRIu64 " possible combinations to construct 0.5 as the  sum the inverse squares of 2 to %" PRIu64 "\n", comb, n);
}
