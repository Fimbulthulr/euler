#ifndef COUNT_COMBINATIONS_H
#define COUNT_COMBINATIONS_H

/*
 * =====================================================================================
 *
 *       Filename:  count_combinations.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/20 15:21:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdint.h>
#include<gmp.h>


uint64_t
count_combinations
	(mpq_t z,
	 uint64_t n_min,
	 uint64_t n_max);

#endif /* COUNT_COMBINATIONS_H */
