/*
 * =====================================================================================
 *
 *       Filename:  dfs_max_tree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/20 18:34:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"dfs_max_tree.h"

uint64_t
dfs_max_tree
	(size_t n,
	 uint64_t *d,
	 uint64_t *f)
{
	uint64_t max = 0;
	for(size_t i = 0; i < n; ++i)
	{
		uint64_t size = f[i] - d[i] + 1;
		size /= 2;
		max = max > size ? max : size;
	}
	return max;
}
