/*
 * =====================================================================================
 *
 *       Filename:  amicable.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/03/20 06:45:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <inttypes.h>
#include <stdio.h>
#include "amicable.h"
#include "int_root.h"
int
test_amicable
    (uint64_t n)
{
	uint64_t r = usqrt_64(n);



	if(n == 1 || n == 2)
	{
		return 0;
	}

	if(r * r > n)
	{
		--r;
	}

	uint64_t sum = 1;

	if(r * r == n)
	{
		sum += r;
		--r;
	}
	for(uint64_t i = 2; i <= r; ++i)
	{
		if(!(n % i) )
		{
			sum += i + n / i;
		}
	}
	if(sum == n)
	{
		return 0;
	}

	uint64_t n_ = sum;

	r = usqrt_64(n_);
	if(r * r > n_)
	{
		--r;
	}
	sum = 1;
	if(r * r == n_)
	{
		sum += r;
		--r;
	}
	for(uint64_t i = 2; i <= r; ++i)
	{
		if(!(n_ % i) )
		{
			sum += i + n_ / i;
		}
	}

	return sum == n;
}



