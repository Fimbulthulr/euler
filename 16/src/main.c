#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF_SIZE 100




int
main
	(int argc,
	 char** argv)
{
	if(argc > 4)
	{
		fprintf(stderr, "Usage: %s [[base] exponent] [representation]\n", argv[0]);
		exit(1);
	}
	size_t b = 2,
	       e = 15,
	       r = 10;
	if(argc == 4)
	{
		b = atoi(argv[1]);
		e = atoi(argv[2]);
		r = atoi(argv[3]);
	}
	if(argc == 3)
	{
		b = atoi(argv[1]);
		e = atoi(argv[2]);
	}
	if(argc == 2)
	{
		e = atoi(argv[1]);
	}

	size_t buf = BUF_SIZE;
	size_t *number = calloc(buf, sizeof(size_t));
	if(!number)
	{
		fprintf(stderr, "Allocation failed!\n");
		exit(1);
	}
	number[0] = 1;
	size_t digits = 1;
	for(size_t i = 0; i < e; ++i)
	{
		size_t carry = 0;
		for(size_t j = 0; j < digits; ++j)
		{
			number[j] *= b;
			number[j] += carry;
			carry = number[j] / r;
			number[j] %= r;
		}
		for(size_t j = digits; carry; ++j)
		{
			if(j == buf)
			{
				number = realloc(number, buf*2*sizeof(size_t));
				if(!number)
				{
					fprintf(stderr, "Allocation failed!\n");
					exit(1);
				}
				memset(number + buf, 0, buf * sizeof(size_t));
				buf *= 2;
			}
			number[j] = carry % r;
			carry /= r;
			++digits;
		}
	}
	size_t sum = 0;
	for(size_t i = 0; i < digits; ++i)
	{
		printf("%zu", number[digits - 1 - i]);
		sum += number[i];
	}
	printf("\nsum of digits: %zu\n", sum);


}
