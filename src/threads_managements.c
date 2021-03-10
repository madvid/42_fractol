/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_managements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:29:01 by mdavid            #+#    #+#             */
/*   Updated: 2021/03/10 15:47:31 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "fractol.h"

void		f_thd(void *ptr)
{
	t_mlx			*mlx;
	static int		y;
	t_ipt			pt;
	t_fpt			coordc;

	y = (y == IMG_LY - 1) ? 0 : y;
	pt = (struct s_ipt){-1, y++, 0};
	mlx = (t_mlx*)ptr;
	while (++(pt.x) < IMG_LX)
		{
			coordc = associated_complex_coord(pt);
			pt.z = mlx->f_fractal(mlx->img, coordc);
			mlx->img->pixels[mlx->img->nb_c * pt.y + pt.x] = ft_viridis(pt.z);
		}
}
