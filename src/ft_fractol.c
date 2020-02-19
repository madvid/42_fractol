/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/19 17:28:00 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"
#include "libft.h"

int		ft_fractal(char *frac, t_img *img)
{
	int		(*tab_frac[3])(t_img *img);

	tab_frac[0] = &ft_julia;
	tab_frac[1] = &ft_mandelbrot;
	tab_frac[2] = &ft_julia2;
	if (ft_strcmp(frac, "Julia") == 0)
		(*(tab_frac[0]))(img);
	if (ft_strcmp(frac, "Mandelbrot") == 0)
		(*(tab_frac[1]))(img);
	if (ft_strcmp(frac, "Julia2") == 0)
		(*(tab_frac[2]))(img);
	return (0);
}

int		ft_julia(t_img *img)
{
	/*int		i = -1;
	int		j = -1;

	while (++i < img->nb_l)
	{
		j = -1;
		while (++j < img->nb_c)
		{
			img->pixels[i * (img->nb_c) + j] = 16121856;
		}
	}*/
	int		x = -1;
	int		y = -1;
	int		i = -1;
	t_fpt	new, old, c;
	int		color, maxIter = 255;

	c.x = -0.7;
	c.y = 0.27015;
	printf("start de Julia\n");
	while (++y < IMG_LY)
	{
		x = -1;
		while (++x < IMG_LX)
		{
			new.x = 1.5 * (x - IMG_LX / 2) / (0.5 * img->move.z * IMG_LX) + img->move.x;
			new.y = (y - IMG_LY / 2) / (0.5 * img->move.z * IMG_LY) + img->move.y;
			i = -1;
			//printf("valeur de new.x = %f\n", new.x);
			//printf("valeur de new.y = %f\n", new.y);
			while (++i < maxIter)
			{
				old.x = new.x;
				old.y = new.y;
				new.x = old.x * old.x - old.y * old.y + img->z_julia.x;
				new.y = 2 * old.x * old.y + img->z_julia.y;
				if ((new.x * new.x + new.y * new.y) > 4)
					break ;
			}
			//printf("valeur de i apres iterations = %d\n", i);
			color = ft_rgb_to_int(255 - i, 0, 0 * (i < maxIter));
			//printf("valeur de color = %d\n", color);
			img->pixels[y * (img->nb_c) + x] = color;
		}
	}
	printf("fin de Julia\n");
	return (0);
}

int		ft_mandelbrot(t_img *img)
{
	int		i = -1;
	int		j = -1;

	while (++i < img->nb_l)
	{
		j = -1;
		while (++j < img->nb_c)
		{
			img->pixels[i * (img->nb_c) + j] = 65280;
		}
	}
	return (0);
}

int		ft_julia2(t_img *img)
{
	int		i = -1;
	int		j = -1;

	while (++i < img->nb_l)
	{
		j = -1;
		while (++j < img->nb_c)
		{
			img->pixels[i * (img->nb_c) + j] = 255;
		}
	}
	return (0);
}
