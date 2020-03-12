/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/03/20 05:32:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "amicable.h"

#define N 10000

int
main
    (int argc,
    char **argv)
{
	uint64_t n = argc == 2 ? atoi(argv[1]) : N;
	uint64_t sum = 0;



#pragma omp parallel for reduction(+:sum)
	for(uint64_t i = 1; i < n; ++i)
	{
		sum += i * test_amicable(i);
		if(test_amicable(i) )
		{
			printf("%" PRIu64 "\n", i);
		}
	}
	printf("sum of all amicable numbers under %" PRIu64 ": %" PRIu64 "\n", n, sum);
}



