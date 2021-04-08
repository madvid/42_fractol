/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:56:54 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 09:58:35 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

/*
** FONCTION: FRAC_NEWTON
** PARAMETRES: z_num [t_ldpt]: complex number to the numerator
**			   z_deno [t_ldpt]: complex number to the denominator
** DESCRIPTION:
**		Calculate the polynomial fraction in the Newton formula
*/

t_ldpt	formula_newton(t_ldpt z, int degree)
{
	t_ldpt		z_num;
	t_ldpt		z_deno;
	t_ldpt		z_newton;
	long double	z_zbar;

	z_num = c_power(z, 3);
	z_deno = c_power(z, 2);
	z_num = (t_ldpt){z_num.x - 1, z_num.y, 0};
	z_deno = (t_ldpt){degree * z_deno.x, degree * z_deno.y, 0};
	z_newton = c_prod(z_num, complex_conjugate(z_deno));
	z_zbar = c_prod(z_deno, complex_conjugate(z_deno)).x;
	z_newton = (t_ldpt){z_newton.x / z_zbar, z_newton.y / z_zbar, 0};
	z_newton = (t_ldpt){z.x - z_newton.x, z.y - z_newton.y, 0};
	return (z_newton);
}

/*
** FONCTION: C_DIST
** PARAMETRES: z1 [t_ldpt]: 1st complex number
**			   z2 [t_ldpt]: 2nd complex number
** DESCRIPTION:
**		Calculates the distance between the 2 complex number
** RETOUR:
*/

long double	c_dist(t_ldpt z1, t_ldpt z2)
{
	t_ldpt			tmp;
	long double		res;

	tmp.x = z1.x - z2.x;
	tmp.y = z1.y - z2.y;
	tmp.z = z1.z - z2.z;
	res = c_module(tmp);
	return (res);
}
