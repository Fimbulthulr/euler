#ifndef INT_ROOT_H
#define INT_ROOT_H

/*
 * =====================================================================================
 *
 *       Filename:  int_root.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/03/20 06:12:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Freyja Walberg (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdint.h>
uint8_t
usqrt_8
    (uint8_t x);


uint16_t
usqrt_16
    (uint16_t x);


uint32_t
usqrt_32
    (uint32_t x);


uint64_t
usqrt_64
    (uint64_t x);


int8_t
sqrt_8
    (int8_t x);


int16_t
sqrt_16
    (int16_t x);


int32_t
sqrt_32
    (int32_t x);


int64_t
sqrt_64
    (int64_t x);


uint8_t
uroot_8
    (uint8_t x,
    uint8_t n);


uint16_t
uroot_16
    (uint16_t x,
    uint16_t n);


uint32_t
uroot_32
    (uint32_t x,
    uint32_t n);


uint64_t
uroot_64
    (uint64_t x,
    uint64_t n);


int8_t
root_8
    (int8_t x,
    int8_t n);


int16_t
root_16
    (int16_t x,
    int16_t n);


int32_t
root_32
    (int32_t x,
    int32_t n);


int64_t
root_64
    (int64_t x,
    int64_t n);




#endif /* INT_ROOT_H */
