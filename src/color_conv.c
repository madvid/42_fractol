/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:38 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:34:48 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION: ft_hsv_to_rgb
** PARAMETRES:	t_hsv hsv: triplet de float representant H-S-V
** DESCRIPTION:
** 	Convertit le triplet HSV en triplet RGB.
** RETOUR:
** 	t_rgb rgb: couleur en rgb.
*/

t_rgb	ft_hsv_to_rgb(t_hsv hsv)
{
	float	c;
	float	x;
	float	m;
	t_rgb	rgb;

	c = hsv.v * hsv.s;
	x = c * (1 - fabs(fmod(hsv.h / 60, 2.0) - 1));
	m = hsv.v - c;
	if (hsv.h < 60)
		rgb = (t_rgb){(c + m) * 255, (x + m) * 255, (0 + m) * 255};
	else if (hsv.h < 120)
		rgb = (t_rgb){(x + m) * 255, (c + m) * 255, (0 + m) * 255};
	else if (hsv.h < 180)
		rgb = (t_rgb){(0 + m) * 255, (c + m) * 255, (x + m) * 255};
	else if (hsv.h < 240)
		rgb = (t_rgb){(0 + m) * 255, (x + m) * 255, (c + m) * 255};
	else if (hsv.h < 300)
		rgb = (t_rgb){(x + m) * 255, (0 + m) * 255, (c + m) * 255};
	else
		rgb = (t_rgb){(c + m) * 255, (0 + m) * 255, (x + m) * 255};
	return (rgb);
}

/*
** FONCTION: ft_rgb_to_hsv
** PARAMETRES:	int red: entier entre 0 et 255
** 				int green: entier entre 0 et 255
** 				int blue: entier entre 0 et 255
** DESCRIPTION:
** 	Convertit le triplet RGB en triplet HSV.
** RETOUR:
** 	t_hsv hsv: couleur en HSV
*/

t_hsv	ft_rgb_to_hsv(int red, int green, int blue)
{
	float	delta;
	float	min;
	t_hsv	hsv;

	hsv.h = 0;
	hsv.v = fmax(fmax(red, green), blue);
	min = fmin(fmin(red, green), blue);
	delta = hsv.v - min;
	hsv.s = ft_flt_tern((hsv.v == 0), 0, delta / hsv.v);
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

int	ft_rgb2_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

/*
** FONCTION:
** PARAMETRES:
** DESCRIPTION:
** RETOUR:
*/

t_rgb	ft_hexa_to_rgb(char *hexa)
{
	t_rgb		rgb;

	if ((hexa != NULL) && (ft_strlen(hexa) != 6))
		return ((t_rgb){0, 0, 0});
	rgb.r = hexa[0] + hexa[1];
	rgb.g = hexa[2] + hexa[3];
	rgb.b = hexa[4] + hexa[5];
	return (rgb);
}

/*
** FONCTION:
** PARAMETRES:
** DESCRIPTION:
** RETOUR:
*/

int	f_cborn(double value)
{
	if (value >= 255)
		return (254);
	if (value <= 0)
		return (1);
	return (value);
}
