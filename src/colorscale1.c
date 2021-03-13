/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorscale1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:12:14 by mdavid            #+#    #+#             */
/*   Updated: 2021/03/13 15:13:18 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION: colorscale_viridis
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_viridis(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)(0.314 * level - 0.00784 * pow(level, 2)
		- 0.0013080 * pow(level, 3) + 0.000019233 * pow(level, 4)
		+ 0.00000009443 * pow(level, 5) - 0.0000000013289 * pow(level, 6)
		+ 69.7);
	c.b = (unsigned char)(3.530 * level + 0.00891 * pow(level, 2)
		- 0.0053269 * pow(level, 3) + 0.000154827 * pow(level, 4)
		- 0.00000178544 * pow(level, 5) + 0.0000000072084 * pow(level, 6)
		+ 84.31);
	c.g = (unsigned char)(3.527 * level + 0.01170 * pow(level, 2)
		- 0.0017233 * pow(level, 3) + 0.000041048 * pow(level, 4)
		- 0.00000039623 * pow(level, 5) + 0.0000000013416 * pow(level, 6)
		+ 1.07);
	ret = ft_rgb2_to_int(c);
	return (ret);
}

/*
** FONCTION: colorscale_magma
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_magma(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)f_cborn(0.511 * level + 0.22447 * pow(level, 2)
		- 0.0074574 * pow(level, 3) + 0.000140706 * pow(level, 4)
		- 0.00000137083 * pow(level, 5) + 0.0000000050574 * pow(level, 6)
		- 0.4);
	c.b = (unsigned char)f_cborn(5.991 * level + 0.04390 * pow(level, 2)
		- 0.0047590 * pow(level, 3) + 0.000053704 * pow(level, 4)
		- 0.00000004673 * pow(level, 5) - 0.0000000009853 * pow(level, 6)
		- 1.88);
	c.g = (unsigned char)f_cborn(1.727 * level - 0.08615 * pow(level, 2)
		+ 0.0034082 * pow(level, 3) - 0.000067154 * pow(level, 4)
		+ 0.00000071042 * pow(level, 5) - 0.0000000028581 * pow(level, 6)
		- 0.22);
	ret = ft_rgb2_to_int(c);
	return (ret);
}

/*
** FONCTION: colorscale_ylorbr
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_ylorbr(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)(0.628 * level - 0.07783 * pow(level, 2)
		+ 0.0033086 * pow(level, 3) - 0.000057547 * pow(level, 4)
		+ 0.00000038166 * pow(level, 5) - 0.0000000008096 * pow(level, 6)
		+ 254.0);
	c.b = (unsigned char)(- 2.635 * level + 0.00194 * pow(level, 2)
		- 0.0035433 * pow(level, 3) + 0.000106270 * pow(level, 4)
		- 0.00000108880 * pow(level, 5) + 0.0000000038323 * pow(level, 6)
		+ 227.20);
	c.g = (unsigned char)(- 0.578 * level + 0.00478 * pow(level, 2)
		- 0.0016461 * pow(level, 3) + 0.000024256 * pow(level, 4)
		- 0.00000010101 * pow(level, 5) + 0.0000000000217 * pow(level, 6)
		+ 255.03);
	ret = ft_rgb2_to_int(c);
	return (ret);
}

/*
** FONCTION: colorscale_mako
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_mako(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)(3.974 * level - 0.13396 * pow(level, 2)
		+ 0.0044157 * pow(level, 3) - 0.000116529 * pow(level, 4)
		+ 0.00000144318 * pow(level, 5) - 0.0000000060359 * pow(level, 6)
		+ 8.6);
	c.b = (unsigned char)(0.843 * level + 0.32081 * pow(level, 2)
		- 0.0112150 * pow(level, 3) + 0.000165340 * pow(level, 4)
		- 0.00000120327 * pow(level, 5) + 0.0000000036499 * pow(level, 6)
		+ 9.27);
	c.g = (unsigned char)(2.113 * level - 0.03664 * pow(level, 2)
		+ 0.0018876 * pow(level, 3) - 0.000029067 * pow(level, 4)
		+ 0.00000018546 * pow(level, 5) - 0.0000000004391 * pow(level, 6)
		+ 3.27);
	ret = ft_rgb2_to_int(c);
	return (ret);
}
