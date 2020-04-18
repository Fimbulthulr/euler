#ifndef DFS_CELLS_H
#define DFS_CELLS_H

/*
 * =====================================================================================
 *
 *       Filename:  dfs_cells.h
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

#include<stdint.h>

void
dfs_cells
	(uint64_t cell_matrix,
	 uint64_t W,
	 uint64_t H,
	 uint64_t *d,
	 uint64_t *f);

#endif /* DFS_CELLS_H */
