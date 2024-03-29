/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_managements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:29:01 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 18:31:25 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION: f_thd1
** PARAMETRES: ptr [void *]: mlx pointer casted to void*
** DESCRIPTION:
**		Edits a lines of pixels (the yth line). Function is for
**		Mandelbrot, Julia and BurningShip.
** RETOUR:
**		None
*/

void	f_thd1(void *ptr)
{
	t_mlx			*mlx;
	static int		y;
	t_ipt			pt;
	t_ldpt			coordc;

	mlx = (t_mlx *)ptr;
	y = ft_int_tern((y == IMG_LY - 1), 0, y);
	pt = (struct s_ipt){-1, y++, 0};
	coordc.y = mlx->img->ratio * (pt.y - 0.5 * IMG_LY) - mlx->img->origin.y;
	while (++(pt.x) < IMG_LX)
	{
		coordc.x = associated_c_coord(pt, mlx->img).x;
		pt.z = mlx->f_fractal(mlx->img, coordc);
		mlx->img->pixels[mlx->img->nb_c * pt.y + pt.x] = mlx->f_color(pt.z);
	}
}

/*
** FONCTION: f_thd1
** PARAMETRES: ptr [void *]: mlx pointer casted to void*
** DESCRIPTION:
**		Edits a lines of pixels (the yth line). Function is for Newton
** RETOUR:
**		None
*/

void	f_thd2(void *ptr)
{
	t_mlx			*mlx;
	static int		y;
	t_ipt			pt;
	t_ldpt			coordc;

	mlx = (t_mlx *)ptr;
	y = ft_int_tern((y == IMG_LY - 1), 0, y);
	pt = (struct s_ipt){-1, y++, 0};
	coordc.y = mlx->img->ratio * (pt.y - 0.5 * IMG_LY) - mlx->img->origin.y;
	while (++(pt.x) < IMG_LX)
	{
		coordc.x = associated_c_coord(pt, mlx->img).x;
		mlx->img->pixels[mlx->img->nb_c * pt.y + pt.x]
			= mlx->f_fractal(mlx->img, coordc);
	}
}
