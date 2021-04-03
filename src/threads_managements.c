/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_managements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:29:01 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/03 22:22:46 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "fractol.h"

void		f_thd1(void *ptr)
{
	t_mlx			*mlx;
	static int		y;
	t_ipt			pt;
	t_fpt			coordc;

	mlx = (t_mlx*)ptr;
	y = (y == IMG_LY - 1) ? 0 : y;
	pt = (struct s_ipt){-1, y++, 0};
	coordc.y = mlx->img->ratio * (pt.y - 0.5 * IMG_LY) - mlx->img->origin.y;
	while (++(pt.x) < IMG_LX)
		{
			coordc.x = associated_c_coord(pt, mlx->img).x;
			pt.z = mlx->f_fractal(mlx->img, coordc);
			mlx->img->pixels[mlx->img->nb_c * pt.y + pt.x] = mlx->f_color(pt.z);
		}
}

void		f_thd2(void *ptr)
{
	t_mlx			*mlx;
	static int		y;
	t_ipt			pt;
	t_fpt			coordc;

	mlx = (t_mlx*)ptr;
	y = (y == IMG_LY - 1) ? 0 : y;
	pt = (struct s_ipt){-1, y++, 0};
	coordc.y = mlx->img->ratio * (pt.y - 0.5 * IMG_LY) - mlx->img->origin.y;
	while (++(pt.x) < IMG_LX)
		{
			coordc.x = associated_c_coord(pt, mlx->img).x;
			mlx->img->pixels[mlx->img->nb_c * pt.y + pt.x]
				= mlx->f_fractal(mlx->img, coordc);
		}
}