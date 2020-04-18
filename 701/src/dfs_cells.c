/*
 * =====================================================================================
 *
 *       Filename:  dfs_cells.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/20 17:04:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"dfs_cells.h"
#include"stddef.h"


void
dfs_visit
	(uint64_t cell_matrix,
	 uint64_t u,
	 uint64_t *visited,
	 uint64_t W,
	 uint64_t H,
	 uint64_t *d,
	 uint64_t *f,
	 uint64_t *t);

void
dfs_cells
	(uint64_t cell_matrix,
	 uint64_t W,
	 uint64_t H,
	 uint64_t *d,
	 uint64_t *f)
{
	uint64_t visited = 0;	//no vertex has bin viseted
	uint64_t t = 0;
	size_t max_visited = 1;
	max_visited <<= W*H;
	max_visited -= 1;
	while(visited < max_visited)
	{
		uint64_t u = 0;
		while(visited & 1<<u)
		{
			++u;
		}
		dfs_visit(cell_matrix, u, &visited, W, H, d, f, &t);
	}
}

void
dfs_visit
	(uint64_t cell_matrix,
	 uint64_t u,
	 uint64_t *visited,
	 uint64_t W,
	 uint64_t H,
	 uint64_t *d,
	 uint64_t *f,
	 uint64_t *t)
{
	*visited |= 1 << u;
	d[u] = (*t)++;
	if(!(cell_matrix & 1<<u))		//white verticies are isolated
	{
		f[u] = (*t)++;
		return;
	}
	//adjacency list: top, left, right, bottom
	uint64_t x = u%W;
	uint64_t y = u/W;
	if(y != 0)//check: is not top row
	{
		uint64_t v = x + (y-1)*W;
		if((cell_matrix & 1<<v)	&& !(*visited & 1<<v ))//only in adjacency list if cell is black, visit only if not already visited
		{
			dfs_visit(cell_matrix, v, visited, W, H, d, f, t);
		}
	}
	if(x != 0)//check: is not leftmost column
	{
		uint64_t v = (x-1) + y*W;
		if((cell_matrix & 1<<v)	&& !(*visited & 1<<v ))//only in adjacency list if cell is black, visit only if not already visited
		{
			dfs_visit(cell_matrix, v, visited, W, H, d, f, t);
		}
	}
	if(x != W-1)//check: is not rightmost column
	{
		uint64_t v = (x+1) + y*W;
		if((cell_matrix & 1<<v)	&& !(*visited & 1<<v ))//only in adjacency list if cell is black, visit only if not already visited
		{
			dfs_visit(cell_matrix, v, visited, W, H, d, f, t);
		}
	}
	if(y != H-1)//check: is not bottom row:
	{
		uint64_t v = x + (y+1)*W;
		if((cell_matrix & 1<<v)	&& !(*visited & 1<<v ))//only in adjacency list if cell is black, visit only if not already visited
		{
			dfs_visit(cell_matrix, v, visited, W, H, d, f, t);
		}
	}

	f[u] = (*t)++;

}
