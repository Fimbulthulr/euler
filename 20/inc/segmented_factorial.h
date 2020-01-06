#ifndef SEGMENTED_FACTORIAL_H
#define SEGMENTED_FACTORIAL_H

/*
 * =====================================================================================
 *
 *       Filename:  segmented_factorial.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/20 00:08:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (), gx231@stud.uni-heidelberg.de
 *   Organization:  Universität Heidelberg
 *
 * =====================================================================================
 */

#include<stdint.h>
#include<stddef.h>
void
segmented_factorial
	(uint64_t n,
	 uint64_t cutoff,
	 size_t n_segments,
	 uint64_t* segments);

#endif /* SEGMENTED_FACTORIAL_H */
