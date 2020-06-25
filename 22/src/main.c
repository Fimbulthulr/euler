/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  24/06/20 06:09:49
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
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <math.h>

#define BUF 100

int
cmpstringp
    (const void *p1,
    const void *p2)
{
	return strcmp(*(char*const*)p1, *(char*const*)p2);
}

uint64_t 
nameval
	(char* name)
{
	uint64_t val = 0;
	for(size_t i = 0; name[i] != '\0'; ++i){
		val += name[i] - 'A' + 1;
	}
	return val;
}


int
main
    (int argc,
    char **argv)
{
	char *file;



	if(argc > 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(1);
	}
	else if(argc == 2)
	{
		file = argv[1];
	}
	else
	{
		file = "names.txt";
	}

	int fd = open(file, O_RDONLY);

	if(fd == -1)
	{
		fprintf(stderr, "Error: could not open file\n");
		exit(1);
	}

	struct stat statbuf;
	int status = fstat(fd, &statbuf);

	if(status == -1)
	{
		fprintf(stderr, "Error: could not retrieve file info\n");
		exit(1);
	}

	size_t filesize = statbuf.st_size;
	char *content = malloc(filesize);
	ssize_t read_bytes = 0;

	while(read_bytes < filesize)
	{
		ssize_t status = read(fd, content + read_bytes, filesize - read_bytes);

		if(status == -1)
		{
			fprintf(stderr, "Error: read failed\n");
			exit(1);
		}
		read_bytes += status;
	}

	uint64_t n_names = 0;

	for(size_t i = 0; i < filesize; ++i)
	{
		if(content[i] == '"')
		{
			n_names += 1;
		}
	}
	if(n_names % 2)
	{
		fprintf(stderr, "Error: file does not match expected format\n");
		exit(1);
	}
	n_names /= 2;

	size_t pos = 0;
	char **names = calloc(sizeof(char*), n_names);

	for(size_t i = 0; i < n_names; ++i)
	{
		for(pos; content[pos] != '"'; ++pos)
		{
			;
		}
		++pos;
		names[i] = content + pos;
		for(pos; content[pos] != '"'; ++pos)
		{
			;
		}
		content[pos] = '\0';
	}

	qsort(names, n_names, sizeof(char*), cmpstringp);
	uint64_t cumsum = 0;
	for(size_t i = 0; i < n_names; ++i)
	{
		cumsum += (i+1)*nameval(names[i]);	
//		printf("log sum size: %.2f\n", log2(cumsum));
	}
	printf("cumulative name score is %" PRIu64"\n", cumsum);
}



