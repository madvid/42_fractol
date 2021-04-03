/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:00:54 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/04 00:20:17 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

/*
** FONCTION: associated_c_coord
** PARAMETRES:
**		mouse [t_fpt*]: coordonnées x et y du curseur de la souris
**		p [t_ipt]: coordonnées (x;y) d'un pixel particulier de l'image.
** DESCRIPTION:
**		La fonction calcul les coordonnées associées au pixel reçu
**		dans le repère dont l'origine est le centre de l'image.
**		Ces coordonnées sont ensuite modifiées en fonction de la position
**		du curseur de la souris.
** RETOUR:
**		..
*/

t_fpt	associated_c_coord(t_ipt p, t_img *img)
{
	t_fpt	coord;

	coord.x = img->ratio * (p.x - 0.5 * IMG_LX) - img->origin.x;
	return (coord);
}

/*
** FONCTION: C_PROD
** PARAMETRES:
**		z1 [t_fpt]: 1er nombre complexe de la multiplication
**		z2 [t_fpt]: 2nd nombre complexe de la multiplication
** DESCRIPTION:
**		Produit entre 2 nombre complexes.
**		La fonction n'est pas protégée contre les overflows pour les
**		la multiplication entre float.
**		Cela est conscient, la protection découle du semi-clipping du
**		zoom (on ne peut pas dezoomer de manière infini).
**	Remarque: Cela permet de ne pas ralentir.
** RETOUR:
**		result [t_fpt]: résultat du produit entre z1 et z2.
*/

t_fpt	complex_conjugate(t_fpt z)
{
	return ((t_fpt){z.x, -z.y, 0});
}

/*
** FONCTION: complex_prod
** PARAMETRES:
**		z1 [t_fpt]: 1er nombre complexe de la multiplication
**		z2 [t_fpt]: 2nd nombre complexe de la multiplication
** DESCRIPTION:
**		Produit entre 2 nombre complexes.
**		La fonction n'est pas protégée contre les overflows pour les
**		la multiplication entre float.
**		Cela est conscient, la protection découle du semi-clipping du
**		zoom (on ne peut pas dezoomer de manière infini).
**	Remarque: Cela permet de ne pas ralentir.
** RETOUR:
**		result [t_fpt]: résultat du produit entre z1 et z2.
*/

t_fpt	c_prod(t_fpt z1, t_fpt z2)
{
	return ((t_fpt){z1.x * z2.x - z1.y * z2.y, z1.x * z2.y + z1.y * z2.x, 0});
}

/*
** FONCTION: complex_power
** PARAMETRES:
**		z [t_fpt]: 1er nombre complexe de la multiplication
**		p [int]: power to which z1 is elevated
** DESCRIPTION:
**		Calculate the power of a complex number.
**		Function is not protected from overflow.
**		This is expected, it allows not performing a test and thus save time.
** RETOUR:
**		result [t_fpt]: result of z elevated to p.
*/

t_fpt	c_power(t_fpt z, int p)
{
	if (p == 1)
		return (z);
	return(c_prod(z, c_power(z, p - 1)));
}

/*
** FONCTION: complex_power
** PARAMETRES:
**		z [t_fpt]: 1er nombre complexe de la multiplication
** DESCRIPTION:
**		Calculate the modulus of a z.
**		Function is not protected from overflow.
**		This is expected, it allows not performing a test and thus save time.
** RETOUR:
**		module [t_fpt]: associated modulus of z number.
*/

long double	c_module(t_fpt z)
{
	return (fabsl(z.x * z.x + z.y * z.y));
}

/*
** FONCTION: C_DIST
** PARAMETRES: z1 [t_fpt]: 1st complex number
**			   z2 [t_fpt]: 2nd complex number
** DESCRIPTION:
**		Calculates the distance between the 2 complex number
** RETOUR:
*/

long double c_dist(t_fpt z1, t_fpt z2)
{
	return (c_module((t_fpt){z1.x - z2.x, z1.y - z2.y, 0}));
}

/*
** FONCTION: FRAC_NEWTON
** PARAMETRES: z_num [t_fpt]: complex number to the numerator
**			   z_deno [t_fpt]: complex number to the denominator
** DESCRIPTION:
**		Calculate the polynomial fraction in the Newton formula
*/

t_fpt		formula_newton(t_fpt z, int degree)
{
	t_fpt		z_num;
	t_fpt		z_deno;
	t_fpt		z_newton;
	long double z_zbar;

	z_num = c_power(z, 3);
	z_deno = c_power(z, 2);
	z_num = (t_fpt){z_num.x - 1, z_num.y, 0};
	z_deno = (t_fpt){degree * z_deno.x, degree * z_deno.y, 0};
	z_newton = c_prod(z_num, complex_conjugate(z_deno));
	z_zbar = c_prod(z_deno, complex_conjugate(z_deno)).x;
	z_newton = (t_fpt){z_newton.x / z_zbar, z_newton.y / z_zbar, 0};
	z_newton = (t_fpt){z.x - z_newton.x, z.y - z_newton.y, 0};
	return (z_newton);
}
