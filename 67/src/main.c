#include<stdio.h>
#include<stddef.h>

#include"67.h"
#include"floorSqrt.h"

//size_t tree[] = {3, 7, 4, 2, 4, 6, 8, 5, 9, 3};

int
main()
{
	size_t n;
	n = sizeof(tree);
	n /= sizeof(tree[0]);
	n = (floorSqrt(8*n+1)-1)/2 - 1;
	for(size_t i = 0; i < n; ++i)
	{
		size_t n1, n2;
		size_t n_ = n-i;
		n1 = (n_*(n_-1))/2;
		n2 = (n_*(n_+1))/2;
		for(size_t j = 0; j < n-i; ++j)
		{
			tree[n1 + j] += tree[n2+j] > tree[n2+j+1] ? tree[n2+j] : tree[n2+j+1];
			
		}
	}
	printf("%zu\n", tree[0]);
	
}
