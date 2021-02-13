/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2021/02/13 15:51:26 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "fractol.h"
#include "libft.h"


/*
** FONCTION:
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
		coordc.y = 2 * coordc.x * coordc.y + img->c.y;
		coordc.x = tmpc.x + img->c.x;
		if ((coordc.x * coordc.x + coordc.y * coordc.y) >= RADIUS)
			break ;
	}
	return (iter);
}

/*
** FONCTION:
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
	int		(*tab_frac[2])(t_img *img, t_fpt coord);

	tab_frac[0] = julia;
	tab_frac[1] = mandelbrot;
	if (ft_strcmp(mlx->img->fractal, "Julia") == 0)
		fractal_construct(mlx, tab_frac[0]);
	if (ft_strcmp(mlx->img->fractal, "Mandelbrot") == 0)
		fractal_construct(mlx, tab_frac[1]);
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

void	fractal_construct(t_mlx *mlx, int (*f_frac)(t_img *img, t_fpt coord))
{
	t_ipt		p;
	void		*thd_ag;
	pthread_t	thds[IMG_LY];

	p.y = -1;
	while (++(p.y) < IMG_LY)
	{
		p.x = -1;
		thd_ag = f_pack_thd_args(&p, mlx->img, f_frac);
		if (pthread_create(&thds[p.y], NULL, (void*)(&f_thd), thd_ag))
			ft_close(mlx);
		if (pthread_join(thds[p.y], NULL))
			ft_close(mlx);
	}
}
