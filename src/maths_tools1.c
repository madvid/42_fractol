/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:00:54 by mdavid            #+#    #+#             */
/*   Updated: 2021/01/17 22:23:15 by mdavid           ###   ########.fr       */
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

t_fpt	associated_complex_coord(t_ipt p)
{
	t_fpt	coord;

	coord.x = 2 * (p.x - 0.5 * IMG_LX) / IMG_LX;
	coord.y = 2 * (p.y - 0.5 * IMG_LY) / IMG_LY;
	return (coord);
}