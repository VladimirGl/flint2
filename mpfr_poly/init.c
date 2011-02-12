/*============================================================================

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

===============================================================================*/
/****************************************************************************

   Copyright (C) 2010 William Hart
   
*****************************************************************************/

#include <stdlib.h>
#include <mpir.h>
#include <mpfr.h>
#include "flint.h"
#include "mpfr_vec.h"
#include "mpfr_poly.h"

void mpfr_poly_init(mpfr_poly_t poly, mp_bitcnt_t prec)
{
   poly->coeffs = NULL;
   
   poly->alloc = 0;
   poly->length = 0;
   poly->prec = prec;
}

void mpfr_poly_init2(mpfr_poly_t poly, const ulong alloc, mp_bitcnt_t prec)
{
   if (alloc) /* allocate space for alloc coefficients */
      poly->coeffs = _mpfr_vec_init(alloc, prec);
   else
      poly->coeffs = NULL;

   poly->alloc = alloc;
   poly->length = 0;
   poly->prec = prec;
}