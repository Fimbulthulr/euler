/*
 * =====================================================================================
 *
 *       Filename:  segmented_factorial.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/20 00:08:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), gx231@stud.uni-heidelberg.de
 *   Organization:  Universität Heidelberg
 *
 * =====================================================================================
 */

#include"segmented_factorial.h"

void
segmented_factorial
	(uint64_t N,
	 uint64_t cutoff,
	 size_t n_segments,
	 uint64_t* segments)
{
	
	for(size_t i = 0; i < n_segments - 1; ++i)
	{
		segments[i] = 0;
	}
	segments[n_segments - 1] = 1;

	for(uint64_t n = 2; n <= N; ++n)
	{
		for(size_t i = 0; i < n_segments; ++i)
		{
			segments[i] *= n;
		}
		for(size_t i = 1; i < n_segments; ++i)
		{
			segments[n_segments-i-1] += segments[n_segments - i] / cutoff;
			segments[n_segments-i] %= cutoff;
		}
	}

}
