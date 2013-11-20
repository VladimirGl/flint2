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

    Copyright (C) 2013 Mike Hansen

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "flint.h"
#include "ulong_extras.h"

int main(void)
{
    int i, j;
    flint_rand_t state;

    flint_printf("primitive_root_prime....");
    fflush(stdout);
   
    flint_randinit(state);

    for (i = 0; i < 100; i++)
    {
        n_factor_t factors;
        mp_limb_t p, root;
        double pinv;
        
        n_factor_init(&factors);
        p = n_randtest_prime(state, 1);
        pinv = n_precompute_inverse(p);
        n_factor(&factors, p - 1, 1);

        root = n_primitive_root_prime(p);
        
        for (j = 0; j < factors.num; j++)
        {
            if (n_powmod_precomp(root, (p-1) / factors.p[j], p, pinv) == 1)
            {
                flint_printf("FAIL:\n");
                flint_printf("%wu ** (%wu / %wu) == 1 mod %wu\n", root, p-1, factors.p[j], p);
                abort();
            }
        }
    }

   flint_randclear(state);

   flint_printf("PASS\n");
   return 0;

}