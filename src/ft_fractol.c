/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2021/01/17 22:24:47 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
	while (++iter < 255)
	{
		tmpc.x = coordc.x * coordc.x - coordc.y * coordc.y;
		coordc.y = 2 * coordc.x * coordc.y + img->cst_julia.y;
		coordc.x = tmpc.x + img->cst_julia.x;
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
	return ((const int)0);
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

void	ft_fractal(char *frac, t_img *img)
{
	int		(*tab_frac[2])(t_img *img, t_fpt coord);

	tab_frac[0] = julia;
	tab_frac[1] = mandelbrot;
	if (ft_strcmp(frac, "Julia") == 0)
		fractal_construct(img, tab_frac[0]);
	if (ft_strcmp(frac, "Mandelbrot") == 0)
		fractal_construct(img, tab_frac[1]);

}

/*
** FONCTION:
** PARAMETRES:
**		img [t_img*]: *structure contenant les pointeurs et variables relatifs
**					  à l'image et un peu plus dans le cas du projet fractol.
**		f_frac [(int*)f]:
** DESCRIPTION:
**		
** RETOUR:
**		Rien.
*/

void	fractal_construct(t_img *img, int (*f_frac)(t_img *img, t_fpt coord))
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
			coordc = associated_complex_coord(p);
			//printf("coord.x = %f -- coord.y =%f\n", coordc.x, coordc.y);
			p.z = f_frac(img, coordc);
			color = ft_viridis(p.z);
			img->pixels[img->nb_c * p.y + p.x] = color;
		}
	}
}
