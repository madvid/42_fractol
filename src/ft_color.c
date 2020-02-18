/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/18 17:07:30 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "libft.h"

/*
**
*/
/*t_hsv	ft_rbg_to_hsv(t_rgb rgb)
{
	float	delta;
	float	min;
	t_hsv	hsv;

	hsv.h = 0;
	hsv.v = fmax(fmax(rgb.r, rgb.g), rgb.b);
	min = fmin(fmin(rgb.r, rgb.g), rgb.b);
	delta = hsv.v - min;
	hsv.s = (hsv.v == 0) ? 0 : delta / hsv.v;

	if (hsv.s == 0)
		hsv.h = 0.0;
	else
	{
		if (rgb.r == hsv.v)
			hsv.h = (rgb.g - rgb.b) / delta;
		else if (rgb.g == hsv.v)
			hsv.h = 2 + (rgb.b - rgb.r) / delta;
		else
			hsv.h = 4 + (rgb.r - rgb.g) / delta;
		hsv.h *= 60;
		if (hsv.h < 0.0)
			hsv.h += 360;
	}
	hsv.v = hsv.v / 255;
	return (hsv);
}*/

t_hsv	ft_rbg_to_hsv(int red, int green, int blue)
{
	float	delta;
	float	min;
	t_hsv	hsv;

	hsv.h = 0;
	hsv.v = fmax(fmax(red, green), blue);
	min = fmin(fmin(red, green), blue);
	delta = hsv.v - min;
	hsv.s = (hsv.v == 0) ? 0 : delta / hsv.v;

	if (hsv.s == 0)
		hsv.h = 0.0;
	else
	{
		if (red == hsv.v)
			hsv.h = (green - blue) / delta;
		else if (green == hsv.v)
			hsv.h = 2 + (blue - red) / delta;
		else
			hsv.h = 4 + (red - green) / delta;
		hsv.h *= 60;
		if (hsv.h < 0.0)
			hsv.h += 360;
	}
	hsv.v = hsv.v / 255;
	return (hsv);
}

/*t_hsv	ft_hsv_to_int(t_hsv hsv)
{
}*/

int		ft_rgb_to_int(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}