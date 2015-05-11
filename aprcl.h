/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2015, Vladimir Glazchev

******************************************************************************/

#ifndef APRCL_H
#define APRCL_H

#include <gmp.h>
#include "flint.h"
#include "fmpz_poly.h"

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct 
{
    fmpz_poly_t poly;
    ulong power;
} _unity_root;

typedef _unity_root unity_root[1];

typedef enum
{
    UNKNOWN,
    COMPOSITE,
    PRIME,
    FAIL_LUCAS,
    FAIL_ADDITIONAL
} return_status_aprcl;

void unity_init(unity_root element, ulong n);
void unity_clear(unity_root element);
void unity_print(unity_root element);
void unity_nth_root(unity_root element, ulong n);
void unity_nth_root_inc(unity_root element, ulong n);
void unity_nth_root_dec(unity_root element, ulong n);
void unity_roots_add(unity_root res, const unity_root element1, const unity_root element2);
void unity_roots_mul(unity_root res, const unity_root element1, const unity_root element2);
void unity_roots_mul_sub(unity_root res, const unity_root element1, const unity_root element2);
void unity_roots_reduce_cyclotomic(unity_root res, ulong p);

mp_ptr f_table(const ulong q);

void jacobi_pq(unity_root result, ulong q, ulong p);
void jacobi_pq_general(unity_root result, const mp_ptr table, ulong p, ulong q, ulong k, ulong a, ulong b);
void jacobi_pq_not2(unity_root result, ulong q, ulong p);
void jacobi_2q_one(unity_root result, ulong q);
void jacobi_2q_two(unity_root result, ulong q);

int is_prime_aprcl(const fmpz_t n);
return_status_aprcl _is_prime_aprcl(const fmpz_t n);

#endif
