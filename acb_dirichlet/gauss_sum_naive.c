/*=============================================================================

    This file is part of ARB.

    ARB is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    ARB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ARB; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2016 Pascal Molin

******************************************************************************/

#include "acb_dirichlet.h"
#include "acb_poly.h"

void
acb_dirichlet_gauss_sum_naive(acb_t res, const acb_dirichlet_group_t G, const acb_dirichlet_char_t chi, slong prec)
{
    acb_t z;
    acb_ptr v;

    v = _acb_vec_init(G->q);
    acb_dirichlet_chi_vec(v, G, chi, G->q, prec);

    acb_init(z);
    acb_dirichlet_nth_root(z, G->q, prec);

    _acb_poly_evaluate(res, v, G->q, z, prec);

    acb_clear(z);
    _acb_vec_clear(v, G->q);
}