/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:00:54 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/19 16:31:57 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fpt	associated_complex_coord(t_fpt mouse, t_ipt p)
{
	t_fpt	coord;

	coord.x = p.x - 0.5 * IMG_LX;
	coord.y = p.y - 0.5 * IMG_LY;
	coord.x = coord.x + (mouse.x - 0.5 * IMG_LX)/ IMG_LX;
	coord.y = coord.y + (mouse.y - 0.5 * IMG_LY)/ IMG_LY;
	// coord.x = 1.5 * (x - IMG_LX / 2) / (0.5 * img->mouse.z * IMG_LX) + img->mouse.x;
	// coord.y = (y - IMG_LY / 2) / (0.5 * img->mouse.z * IMG_LY) + img->mouse.y;
	return (coord);
}