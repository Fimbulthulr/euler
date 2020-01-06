/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/09/19 22:23:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), gx231@stud.uni-heidelberg.de
 *   Organization:  Universität Heidelberg
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

  
size_t 
lattice
	(size_t n,
	 size_t m);


int
main
	(int argc,
	 char** argv)
{
	if(argc != 1 && argc != 3)
	{
		fprintf(stderr, "Usage: %s [n1 n2]\n", argv[0]);
		exit(1);
	}
	size_t n = 2,
	       m = 2;
	if(argc == 3)
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
	}
	printf("In a %zux%zu grid, there are %zu possible lattice paths\n", n, m, lattice(n, m));

}





size_t 
lattice_internal
	(size_t n,
	 size_t m,
	 size_t n_max,
	 size_t* matrix)
{
	if(!(n*m))
	{
		printf("shouldn't happen\n");
		return 1;
	}
	size_t n_path = 0, 
	       m_path = 0;
	if(n == 1)
	{
		n_path = 1;
	}
	else if(matrix[ (n-2) + (m-1)*n_max])
	{
		n_path = matrix[(n-2) + (m-1)*n_max];
	}
	else
	{
		n_path = lattice_internal(n-1, m, n_max, matrix);
		matrix[(n-2) + (m-1)*n_max] = n_path;
	}

	if(m == 1)
	{
		m_path = 1;
	}
	else if(matrix[ (n-1) + (m-2)*n_max])
	{
		m_path = matrix[(n-1) + (m-2)*n_max];
	}
	else
	{
		m_path = lattice_internal(n, m - 1, n_max, matrix);
		matrix[(n-1) + (m-2)*n_max] = m_path;
	}
	return n_path + m_path;
}

size_t 
lattice
	(size_t n,
	 size_t m)
{
	size_t* matrix = calloc(n*m, sizeof(size_t));
	if(!matrix)
	{
		fprintf(stderr, "Error: Allocation failed\n");
		exit(1);
	}
	return lattice_internal(n, m, n, matrix);
}
