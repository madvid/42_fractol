/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/19 16:57:02 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"
#include "libft.h"

int		julia(t_img *img, t_fpt coordc)
{
	int		iter = -1;
	t_fpt	tmpc;

	tmpc = coordc;
	iter = -1;
	while (++iter < 255)
	{
		tmpc = coordc;
		coordc.x = tmpc.x * tmpc.x - tmpc.y * tmpc.y + img->cst_julia.x;
		coordc.y = 2 * tmpc.x * tmpc.y + img->cst_julia.y;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) > 4)
			break ;
	}
	printf("fin de Julia\n");
	return (iter);
}

int		mandelbrot(t_img *img, t_fpt coordc)
{
	int		iter;
	t_fpt	tmpc;
	int		j;

	iter = -1;
	tmpc = coordc;
	while (++iter < img->nb_l)
	{
		j = -1;
		while (++j < img->nb_c)
		{
			img->pixels[iter * (img->nb_c) + j] = 65280;
		}
	}
	return (0);
}

int		julia2(t_img *img)
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

int		ft_fractal(char *frac, t_img *img)
{
	static int		(*tab_frac[2])(t_img *img, t_fpt coord) = {&julia, &mandelbrot};
	int				(*fct_frac)(t_img *img, t_fpt coord);

	if (ft_strcmp(frac, "Julia") == 0)
		fct_frac = *(tab_frac[0]);
	if (ft_strcmp(frac, "Mandelbrot") == 0)
		fct_frac = *(tab_frac[1]);
	fractal_construction(img, fct_frac);
	return (0);
}

void	fractal_construction(t_img *img, int (*fct_frac(t_img *img, t_fpt coord)))
{
	t_ipt		p;
	t_fpt		coordc;
	int			color;

	p.y = -1;
	while (++(p.y) < IMG_LY)
	{
		p.x = -1;
		while (++(p.x) < IMG_LX)
		{
			p.z = -1;
			coordc = associated_complex_coord(img->mouse, p);
			p.z = (int)fct_frac(img, coordc);
			color = ft_rgb_to_int(255 - p.z, 0, 0 * (p.z < 255));
			img->pixels[p.y * (img->nb_c) + p.x] = color;
		}
	}
}
