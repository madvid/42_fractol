/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:38 by mdavid            #+#    #+#             */
/*   Updated: 2021/01/30 15:26:23 by mdavid           ###   ########.fr       */
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
	x = c * (1 - fabs(fmod(hsv.h/60, 2.0) - 1));
	m = hsv.v - c;
	if (hsv.h < 60)
	{
		rgb.r = (c + m) * 255;
		rgb.g = (x + m) * 255;
		rgb.b = (0 + m) * 255;
	}
	else if (hsv.h < 120)
	{
		rgb.r = (x + m) * 255;
		rgb.g = (c + m) * 255;
		rgb.b = (0 + m) * 255;
	}
	else if (hsv.h < 180)
	{
		rgb.r = (0 + m) * 255;
		rgb.g = (c + m) * 255;
		rgb.b = (x + m) * 255;
	}
	else if (hsv.h < 240)
	{
		rgb.r = (0 + m) * 255;
		rgb.g = (x + m) * 255;
		rgb.b = (c + m) * 255;
	}
	else if (hsv.h < 300)
	{
		rgb.r = (x + m) * 255;
		rgb.g = (0 + m) * 255;
		rgb.b = (c + m) * 255;
	}
	else
	{
		rgb.r = (c + m) * 255;
		rgb.g = (0 + m) * 255;
		rgb.b = (x + m) * 255;
	}
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

int		ft_rgb2_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

int		ft_rgb_to_int(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

/*
t_rgb	ft_hexa_to_rgb(char *hexa)
{
	t_rgb		rgb;

	if ((hexa != NULL) && (ft_strlen(hexa) != 6))
		return (NULL);
	reg.r = hexa[0] + hexa[1];
	reg.g = hexa[2] + hexa[3];
	reg.b = hexa[4] + hexa[5];
	
}
*/

/*
**
**
**
*/

int		ft_viridis(int level)
{
	t_rgb		c;
	int			ret;

	c.r = (unsigned char)(0.399*level -1.406*pow(level,2) + 0.101*pow(level,3) + 74.014);
	c.g = (unsigned char)(16.8421*level -0.138*pow(level,2) -0.0059*pow(level,3) + 3.937);
	c.b = (unsigned char)(18.567*level -1.536*pow(level,2) + 0.0199*pow(level,3) + 84.974);
	ret = ft_rgb_to_int(c.r, c.g, c.b);
	return (ret);
}

/*
**
**
**
*/

int		ft_magma(int level)
{
	t_rgb		c;
	int			ret;

	c.g = (unsigned char)(-18.52*level - 0.409*pow(level,2) + 0.0035*pow(level,3) + 70.58);
	c.r = (unsigned char)(9.643*level -1.329*pow(level,2) + 0.040*pow(level,3) + 141.398);
	c.b = (unsigned char)(-2.797*level -0.571*pow(level,2) - 0.006*pow(level,3) + 44.25);
	ret = ft_rgb_to_int(c.r, c.g, c.b);
	return (ret);
}