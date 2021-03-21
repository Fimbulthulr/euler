module lexiographic_permutation;
import std.algorithm;

ulong
lexiographic_permutation
	(int[] arr,
	 ulong n)
{
	ulong factorial(ulong k)
	{
		ulong f = 1;
		foreach(ulong i; 2..k+1)
		{
			f *= i;
		}
		return f;
	}

	ulong
	lexiographic_permutation_step
		(int[] arr,
		 ulong n)
	{
		ulong ret = 0;
		if(arr.length > 1)
		{
			arr.sort();
			const ulong p = factorial(arr.length-1);
			const ulong idx = n/p;
//			swap(arr[0], arr[idx]);
			int tmp = arr[idx];
			arr[idx] = arr[0];
			arr[0] = tmp;
			ret = lexiographic_permutation_step(arr[1..$], n%p);
		}
		return ret;
	}
	ulong ret;
	if(n >= factorial(arr.length))
	{
		ret =  1;
	}
	else
	{
		ret = lexiographic_permutation_step(arr, n-1);
	}
	return ret;
}
