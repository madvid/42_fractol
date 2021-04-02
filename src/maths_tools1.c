/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:00:54 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/02 22:54:34 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** FONCTION: associated_complex_coord
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

t_fpt	associated_complex_coord(t_ipt p, t_img *img)
{
	t_fpt	coord;

	coord.x = img->ratio * (p.x - 0.5 * IMG_LX) - img->origin.x;
	return (coord);
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

t_fpt	complex_prod(t_fpt z1, t_fpt z2)
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

t_fpt	complex_power(t_fpt z, int p)
{
	t_fpt	res;

	if (p > 2)
		res = complex_power(z, p - 1);
	res = complex_prod(z, z);
	return (res);
}