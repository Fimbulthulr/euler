/*
 * =====================================================================================
 *
 *       Filename:  int_root.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/03/20 06:12:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (),
 *   Organization:
 *
 * =====================================================================================
 */

#include "int_root.h"


uint8_t
usqrt_8
    (uint8_t x)
{
	uint8_t r = 1, e = 1;



	while(e)
	{
		if(r < x / r)
		{
			e = (x / r - r) / 2;
			r += e;
		}
		else
		{
			e = (r - x / r) / 2;
			r -= e;
		}
	}

	return r;
}




uint16_t
usqrt_16
    (uint16_t x)
{
	uint16_t r = 1, e = 1;



	while(e)
	{
		if(r < x / r)
		{
			e = (x / r - r) / 2;
			r += e;
		}
		else
		{
			e = (r - x / r) / 2;
			r -= e;
		}
	}

	return r;
}




uint32_t
usqrt_32
    (uint32_t x)
{
	uint32_t r = 1, e = 1;



	while(e)
	{
		if(r < x / r)
		{
			e = (x / r - r) / 2;
			r += e;
		}
		else
		{
			e = (r - x / r) / 2;
			r -= e;
		}
	}

	return r;
}




uint64_t
usqrt_64
    (uint64_t x)
{
	uint64_t r = 1, e = 1;



	while(e)
	{
		if(r < x / r)
		{
			e = (x / r - r) / 2;
			r += e;
		}
		else
		{
			e = (r - x / r) / 2;
			r -= e;
		}
	}

	return r;
}




int8_t
sqrt_8
    (int8_t x)
{
	int8_t r = 0, e = 1;



	while(e)
	{
		r += e;
		e = (x / r - r) / 2;
	}

	return r;
}




int16_t
sqrt_16
    (int16_t x)
{
	int16_t r = 0, e = 1;



	while(e)
	{
		r += e;
		e = (x / r - r) / 2;
	}

	return r;
}




int32_t
sqrt_32
    (int32_t x)
{
	int32_t r = 0, e = 1;



	while(e)
	{
		r += e;
		e = (x / r - r) / 2;
	}

	return r;
}




int64_t
sqrt_64
    (int64_t x)
{
	int64_t r = 0, e = 1;



	while(e)
	{
		r += e;
		e = (x / r - r) / 2;
	}

	return r;
}




uint8_t
uroot_8
    (uint8_t x,
    uint8_t n)
{
	uint8_t r = 1, e = 1, r_p, n_, r_n;



	while(e)
	{
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		if(r < x / r_n)
		{
			e = (x / r_n - r) / n;
			r += e;
		}
		else
		{
			e = (r - x / r_n) / n;
			r -= e;
		}
	}

	return r;
}




uint16_t
uroot_16
    (uint16_t x,
    uint16_t n)
{
	uint16_t r = 1, e = 1, r_p, n_, r_n;



	while(e)
	{
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		if(r < x / r_n)
		{
			e = (x / r_n - r) / n;
			r += e;
		}
		else
		{
			e = (r - x / r_n) / n;
			r -= e;
		}
	}

	return r;
}




uint32_t
uroot_32
    (uint32_t x,
    uint32_t n)
{
	uint32_t r = 1, e = 1, r_p, n_, r_n;



	while(e)
	{
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		if(r < x / r_n)
		{
			e = (x / r_n - r) / n;
			r += e;
		}
		else
		{
			e = (r - x / r_n) / n;
			r -= e;
		}
	}

	return r;
}




uint64_t
uroot_64
    (uint64_t x,
    uint64_t n)
{
	uint16_t r = 1, e = 1, r_p, n_, r_n;



	while(e)
	{
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		if(r < x / r_n)
		{
			e = (x / r_n - r) / n;
			r += e;
		}
		else
		{
			e = (r - x / r_n) / n;
			r -= e;
		}
	}

	return r;
}




int8_t
root_8
    (int8_t x,
    int8_t n)
{
	int8_t r = 0, e = 1, r_p, n_, r_n;



	while(e)
	{
		r += e;
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		e = (x / r_n - r) / n;
	}

	return r;
}




int16_t
root_16
    (int16_t x,
    int16_t n)
{
	int16_t r = 0, e = 1, r_p, n_, r_n;



	while(e)
	{
		r += e;
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		e = (x / r_n - r) / n;
	}

	return r;
}




int32_t
root_32
    (int32_t x,
    int32_t n)
{
	int32_t r = 0, e = 1, r_p, n_, r_n;



	while(e)
	{
		r += e;
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		e = (x / r_n - r) / n;
	}

	return r;
}




int64_t
root_64
    (int64_t x,
    int64_t n)
{
	int64_t r = 0, e = 1, r_p, n_, r_n;



	while(e)
	{
		r += e;
		for(n_ = n - 1, r_p = r, r_n = 1; n_; r_p *= r_p, n_ >>= 1)
		{
			r_n *= n_ & 1 ? r_p : 1;
		}
		e = (x / r_n - r) / n;
	}

	return r;
}



