/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorscale2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:12:11 by mdavid            #+#    #+#             */
/*   Updated: 2021/03/13 15:13:33 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION: colorscale_coolwarm
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_coolwarm(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)(3.051 * level + 0.00452 * pow(level, 2)
		+ 0.0005651 * pow(level, 3) - 0.000013849 * pow(level, 4)
		+ 0.00000004519 * pow(level, 5) + 0.0000000001371 * pow(level, 6)
		+ 58.0);
	c.b = (unsigned char)(4.001 * level - 0.04748 * pow(level, 2)
		- 0.0004039 * pow(level, 3) - 0.000010874 * pow(level, 4)
		+ 0.00000026811 * pow(level, 5) - 0.0000000012727 * pow(level, 6)
		+ 191.85);
	c.g = (unsigned char)(5.851 * level - 0.18726 * pow(level, 2)
		+ 0.0085148 * pow(level, 3) - 0.000200397 * pow(level, 4)
		+ 0.00000197850 * pow(level, 5) - 0.0000000070480 * pow(level, 6)
		+ 73.39);
	ret = ft_rgb2_to_int(c);
	return (ret);
}

/*
** FONCTION: colorscale_coolwarm
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_blues(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)(-3.500 * level + 0.20093 * pow(level, 2)
		- 0.0091912 * pow(level, 3) + 0.000165665 * pow(level, 4)
		- 0.00000134727 * pow(level, 5) + 0.0000000042007 * pow(level, 6)
		+ 249.4);
	c.b = (unsigned char)(-0.630 * level + 0.00747 * pow(level, 2)
		- 0.0006070 * pow(level, 3) + 0.000010508 * pow(level, 4)
		- 0.00000006396 * pow(level, 5) + 0.0000000000294 * pow(level, 6)
		+ 254.94);
	c.g = (unsigned char)(-1.618 * level + 0.03248 * pow(level, 2)
		- 0.0009406 * pow(level, 3) + 0.000005845 * pow(level, 4)
		+ 0.00000002159 * pow(level, 5) - 0.0000000002295 * pow(level, 6)
		+ 251.80);
	ret = ft_rgb2_to_int(c);
	return (ret);
}

/*
** FONCTION: colorscale_coolwarm
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_reds(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)f_cborn(1.170 * level - 0.15185 * pow(level, 2)
		+ 0.0066895 * pow(level, 3) - 0.000128050 * pow(level, 4)
		+ 0.00000107218 * pow(level, 5) - 0.0000000033608 * pow(level, 6)
		+ 252.9);
	c.b = (unsigned char)f_cborn(-1.322 * level - 0.11653 * pow(level, 2)
		+ 0.0022018 * pow(level, 3) - 0.000016529 * pow(level, 4)
		+ 0.00000007751 * pow(level, 5) - 0.0000000002541 * pow(level, 6)
		+ 238.76);
	c.g = (unsigned char)f_cborn(0.178 * level - 0.22208 * pow(level, 2)
		+ 0.0081985 * pow(level, 3) - 0.000163815 * pow(level, 4)
		+ 0.00000158409 * pow(level, 5) - 0.0000000057028 * pow(level, 6)
		+ 242.38);
	ret = ft_rgb2_to_int(c);
	return (ret);
}

/*
** FONCTION: colorscale_coolwarm
** PARAMETRES:	int level:
** DESCRIPTION:
**	...
** RETOUR:
**	valeur RGB encodée sur un integer.
*/

int		colorscale_greens(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)f_cborn(-1.813 * level + 0.04956 * pow(level, 2)
		- 0.0036134 * pow(level, 3) + 0.000069534 * pow(level, 4)
		- 0.00000057705 * pow(level, 5) + 0.0000000018706 * pow(level, 6)
		+ 248.0);
	c.b = (unsigned char)f_cborn(-1.662 * level + 0.02270 * pow(level, 2)
		- 0.0033476 * pow(level, 3) + 0.000086716 * pow(level, 4)
		- 0.00000086794 * pow(level, 5) + 0.0000000030781 * pow(level, 6)
		+ 245.08);
	c.g = (unsigned char)f_cborn(-0.099 * level - 0.05145 * pow(level, 2)
		+ 0.0017250 * pow(level, 3) - 0.000036728 * pow(level, 4)
		+ 0.00000035709 * pow(level, 5) - 0.0000000012864 * pow(level, 6)
		+ 251.31);
	ret = ft_rgb2_to_int(c);
	return (ret);
}
