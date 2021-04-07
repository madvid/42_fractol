/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/07 21:26:44 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION: julia
** PARAMETRES: img [t_img*]:pointer on img struct variable
**							(containing render and fractal related variables).
**			   coordc [t_ldpt*]: complex coordinates associated to a pixel
** DESCRIPTION:
**		Funtion is the core of Julia fractal creation.
**		It calculates the iteration for the color of the pixels
**		based on the julia formula.
** RETOUR:
**		iter[int]: iteration needed to determine the color
*/

int	julia(t_img *img, t_ldpt coordc)
{
	int		iter;

	iter = -1;
	while (++iter < img->nb_iter)
	{
		coordc = c_power(coordc, img->degree);
		coordc.x += img->cst.x;
		coordc.y += img->cst.y;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter);
}

/*
** FONCTION: mandelbrot
** PARAMETRES: img [t_img*]:pointer on img struct variable
**							(containing render and fractal related variables).
**			   coordc [t_ldpt*]: complex coordinates associated to a pixel
** DESCRIPTION:
**		Funtion is the core of Mandelbrot fractal creation.
**		It calculates the iteration for the color of the pixels
**		based on the mandelbrot formula.
** RETOUR:
**		iter[int]: iteration needed to determine the color
*/

int	mandelbrot(t_img *img, t_ldpt coordc)
{
	int		iter;
	t_ldpt	c;

	iter = -1;
	c = coordc;
	while (++iter < img->nb_iter)
	{
		coordc = c_power(coordc, img->degree);
		coordc.x += c.x;
		coordc.y += c.y;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter);
}

/*
** FONCTION: burningship
** PARAMETRES:  img [t_img*]:pointer on img struct variable
**							(containing render and fractal related variables).
**			   coordc [t_ldpt*]: complex coordinates associated to a pixel
** DESCRIPTION:
**		Funtion is the core of Burningship fractal creation.
**		It calculates the iteration for the color of the pixels
**		based on the burningship formula.
** RETOUR:
**		iter[int]: iteration needed to determine the color
*/

int	burningship(t_img *img, t_ldpt coordc)
{
	int		iter;
	t_ldpt	tmpc;
	t_ldpt	c;

	iter = -1;
	c = coordc;
	while (++iter < img->nb_iter)
	{
		tmpc.x = coordc.x * coordc.x - coordc.y * coordc.y;
		coordc.y = 2 * fabsl(coordc.x * coordc.y) + c.y;
		coordc.x = tmpc.x + c.x;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter);
}

/*
** FONCTION: classic_newton
** PARAMETRES: img [t_img*]:pointer on img struct variable
**							(containing render and fractal related variables).
**			   coordc [t_ldpt*]: complex coordinates associated to a pixel
** DESCRIPTION:
**		Funtion is the core of Newton fractal creation.
**		It calculates the iteration for the color of the pixels
**		based on the burningship formula.
** RETOUR:
**		iter[int]: iteration needed to determine the color
*/

int	classic_newton(t_img *img, t_ldpt coordc)
{
	int		iter;
	t_ldpt	tmpc;

	iter = -1;
	while (++iter < img->nb_iter)
	{
		tmpc = coordc;
		coordc = formula_newton(coordc, 3);
		if (c_dist(coordc, img->root1) < 0.01)
			return (colorscale_blues(iter));
		if (c_dist(coordc, img->root2) < 0.01)
			return (colorscale_greens(iter));
		if (c_dist(coordc, img->root3) < 0.01)
			return (colorscale_reds(iter));
	}
	return (16777215);
}

/*
** FONCTION: fractal_construct
** PARAMETRES: mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Runs the multithreading process to draw the fractal.
** RETOUR:
**		None.
*/

void	fractal_construct(t_mlx *mlx)
{
	int			idx;
	pthread_t	thds[IMG_LY];
	void		(*f_thd)(void *ptr);

	idx = -1;
	if (ft_strcmp(mlx->img->fractal, "Newton"))
		f_thd = f_thd1;
	else
		f_thd = f_thd2;
	while (++idx < IMG_LY)
	{
		if (pthread_create(&thds[idx], NULL, (void *)(f_thd), (void *)(mlx)))
			ft_close(mlx);
	}
	idx = -1;
	while (++idx < IMG_LY)
		if (pthread_join(thds[idx], NULL))
			ft_close(mlx);
}
