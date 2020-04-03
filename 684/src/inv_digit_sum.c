/*
 * =====================================================================================
 *
 *       Filename:  inv_digit_sum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/20 06:17:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"inv_digit_sum.h"
#include<stddef.h>

#define p 1000000007

uint64_t
inv_digit_sum
	(uint64_t n)
{

	uint64_t r;
	uint64_t k = n/9;
	uint64_t i = k/18;
	k %= 18;
	r = (n > 8? 6: 0) + (n%9+1)*(n%9+2)/2 - 1;
	{
		for(size_t j = 0; j < k; ++j)
		{
			r *= 10;
			r %= p;
		}
		uint64_t r_l = 1, 
		         r_mul = 49;
		for(i; i; i >>=1)
		{
			if(i & 1)
			{
				r_l *= r_mul;
				r_l %= p;
			}
			r_mul *= r_mul;
			r_mul %= p;
		}
		r *= r_l;
		r %= p;
	}
	r += p;
	if(n > 8)
	{
		r -= 6;
	}
	r -= n%p;
	return r%p;
	
}

