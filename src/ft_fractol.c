/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2021/03/12 11:10:35 by mdavid           ###   ########.fr       */
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
	t_fpt	tmpc;

	iter = -1;
	while (++iter < img->max_iter)
	{
		tmpc.x = coordc.x * coordc.x - coordc.y * coordc.y;
		coordc.y = 2 * coordc.x * coordc.y + img->cst.y;
		coordc.x = tmpc.x + img->cst.x;
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
	t_fpt	tmpc;
	t_fpt	c;

	iter = -1;
	c = coordc;
	while (++iter < img->max_iter)
	{
		tmpc.x = coordc.x * coordc.x - coordc.y * coordc.y;
		coordc.y = 2 * coordc.x * coordc.y + c.y;
		coordc.x = tmpc.x + c.x;
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

int		burningship(t_img *img, t_fpt coordc)
{
	int		iter;
	t_fpt	tmpc;
	t_fpt	c;

	iter = -1;
	c = coordc;
	while (++iter < img->max_iter)
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

int		classic_newton(t_img *img, t_fpt coordc)
{
	int		iter;
	t_fpt	tmpc;

	iter = -1;
	while (++iter < img->max_iter) // delta de convergence vers une des racines plutot
	{
		tmpc.x = 3*pow(coordc.x,2) + 6*pow(coordc.x,5) - 3*pow(coordc.y,2) - 60*pow(coordc.x,3) * pow(coordc.y,2) + 30*coordc.x*pow(coordc.y,4);
		coordc.y = 30*pow(coordc.x,4)*coordc.y - 60*pow(coordc.x,2)*pow(coordc.y,3) + 6*coordc.x*coordc.y + 6*pow(coordc.y,5);
		coordc.x = tmpc.x;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter); // couleur spécifique en fonction de la racine vers laquelle z converge ou 0 sinon
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

//void	fractal_construct(t_mlx *mlx, int (*f_frac)(t_img *img, t_fpt coord))
void	fractal_construct(t_mlx *mlx)
{
	t_ipt		p;
	pthread_t	thds[IMG_LY];
	t_img		*img;

	img = mlx->img;
	p.y = -1;
	while (++(p.y) < IMG_LY)
	{
		p.x = -1;
		if (pthread_create(&thds[p.y], NULL, (void*)(&f_thd), (void*)(mlx)))
			ft_close(mlx);
	}
	p.y = -1;
	while (++(p.y) < IMG_LY)
		if (pthread_join(thds[p.y], NULL))
			ft_close(mlx);
}
