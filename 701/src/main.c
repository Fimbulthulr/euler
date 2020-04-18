/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/20 18:11:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<math.h>

#include"dfs_cells.h"
#include"dfs_max_tree.h"

#define W 2
#define H 2

#define P 0.5

#define BUCKETS 1000000

#define USE_BUILTIN 1	//use builtin popcount function

int
main
	(int argc,
	 char **argv)
{
	uint64_t w = W;
	uint64_t h = H;
	double p = P;
	if(argc >= 3)
	{
		w = atoi(argv[1]);
		h = atoi(argv[2]);
	}


	if(w*h > 64)
	{
		fprintf(stderr, "ERROR: rectangle dimension too large!\n");
		exit(1);
	}
	double expectation = 0;
#pragma omp parallel
	{
		uint64_t *d = calloc(w*h, sizeof(uint64_t));
		uint64_t *f = calloc(w*h, sizeof(uint64_t));
		double *local_expectation = calloc(BUCKETS,sizeof(double));
#pragma omp for
		for(uint64_t i = 1; i < (uint64_t) 1<< (uint64_t)w*h; ++i)
		{
			if(i == (1<<w*h)-1)
			{
				local_expectation[i % BUCKETS] += w*h*pow(p, w*h);
				continue;
			}
			
			uint64_t pop;
#ifdef USE_BUILTIN
			pop = __builtin_popcountl(i);
#else
			//TODO: alternative popcount
			pop = 0;
#endif
			double probability = pow(p, pop);
			probability *= pow(1-p, w*h - pop);
			dfs_cells(i, w, h, d, f);
			uint64_t area = dfs_max_tree(w*h, d, f);
			local_expectation[i%BUCKETS] += area*probability;
		}
		free(d);
		free(f);
		for(size_t i = 1; i < BUCKETS; ++i)
		{
			local_expectation[0] += local_expectation[i];
		}

#pragma omp critical
		expectation += local_expectation[0];
		free(local_expectation);
	}
	printf("the expected maximal area in a %"PRIu64" by %"PRIu64" rectangle for a probability of %f is %.8e\n", w, h, p, expectation);
}
