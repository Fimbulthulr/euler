#include<stddef.h>
#include"floorSqrt.h"


size_t
floorSqrt
	(size_t x)
{
	if(x == 1 || x == 0)
		return x;

	size_t s = 1,
	       e = x;
	size_t ans = 0;
	while(s <= e)
	{
		size_t mid = (s+e)/2;
		if(mid*mid == x)
		{
			return mid;
		}
		else if(mid*mid < x)
		{
			s = mid+1;
			ans = mid;
		}
		else
			e = mid - 1;
	}
	return ans;
	
}
