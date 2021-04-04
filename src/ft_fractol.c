/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/04 22:18:58 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION: julia
** PARAMETRES:
**		img [t_img*]:*structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
**		coordc [t_fpt*]:
** DESCRIPTION:
**		Fonction pour d'attribuer la couleur aux pixels pour le fractal Julia
** RETOUR:
**		iter[int]: ...
*/

int		julia(t_img *img, t_fpt coordc)
{
	int		iter;

	iter = -1;
	while (++iter < img->nb_iter)
	{
		coordc = c_prod(coordc, coordc);
		coordc.x += img->cst.x;
		coordc.y += img->cst.y;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter);
}

/*
** FONCTION: mandelbrot
** PARAMETRES:
**		img [t_img*]:*structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
**		coordc [t_fpt*]:
** DESCRIPTION:
**		Fonction pour d'attribuer la couleur aux pixels pour le fractal Julia
** RETOUR:
**		iter[int]: ...
*/

int		mandelbrot(t_img *img, t_fpt coordc)
{
	int		iter;
	t_fpt	c;

	iter = -1;
	c = coordc;
	while (++iter < img->nb_iter)
	{
		coordc = c_prod(coordc, coordc);
		coordc.x += c.x;
		coordc.y += c.y;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter);
}

/*
** FONCTION: burningship
** PARAMETRES:
**		img [t_img*]:*structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
**		coordc [t_fpt*]:
** DESCRIPTION:
**		Fonction pour d'attribuer la couleur aux pixels pour le fractal Julia
** RETOUR:
**		iter[int]: ...
*/

int		burningship(t_img *img, t_fpt coordc)
{
	int		iter;
	t_fpt	tmpc;
	t_fpt	c;

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
** PARAMETRES:
**		img [t_img*]:*structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
**		coordc [t_fpt*]:
** DESCRIPTION:
**		Fonction pour d'attribuer la couleur aux pixels pour le fractal Julia
** RETOUR:
**		iter[int]: ...
*/

int		classic_newton(t_img *img, t_fpt coordc)
{
	int		iter;
	t_fpt	tmpc;

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
** FONCTION:
** PARAMETRES:
**		frac [char*]: nom du fractale qui va être affiché
**		img [t_img*]: *structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
** DESCRIPTION:
**		Initialisation d'un tableau de pointeur sur fonction et appelle à la
**		fonction permettant de "dessiner" la première image du fractale.
** RETOUR:
***		Rien.
*/

void	ft_fractal(t_mlx *mlx)
{
	if (ft_strcmp(mlx->img->fractal, "Julia") == 0)
		mlx->f_fractal = julia;
	if (ft_strcmp(mlx->img->fractal, "Mandelbrot") == 0)
		mlx->f_fractal = mandelbrot;
	if (ft_strcmp(mlx->img->fractal, "BurningShip") == 0)
		mlx->f_fractal = burningship;
	if (ft_strcmp(mlx->img->fractal, "Newton") == 0)
		mlx->f_fractal = classic_newton;
}

/*
** FONCTION:
** PARAMETRES:
**		img [t_img*]: *structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
**		f_frac [(int*)f]:
** DESCRIPTION:
** RETOUR:
**		Rien.
*/

void	fractal_construct(t_mlx *mlx)
{
	t_ipt		p;
	pthread_t	thds[IMG_LY];
	t_img		*img;
	void		(*f_thd)(void *ptr);

	img = mlx->img;
	p.y = -1;
	if (ft_strcmp(mlx->img->fractal, "Newton"))
		f_thd = f_thd1;
	else
		f_thd = f_thd2;
	while (++(p.y) < IMG_LY)
	{
		p.x = -1;
		if (pthread_create(&thds[p.y], NULL, (void*)(f_thd), (void*)(mlx)))
			ft_close(mlx);
	}
	p.y = -1;
	while (++(p.y) < IMG_LY)
		if (pthread_join(thds[p.y], NULL))
			ft_close(mlx);
}
