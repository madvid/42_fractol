/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:52:39 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/07 22:00:10 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fractol.h"

/*
** FONCTION : usage
** PARAMETRES :	int ac: nb de parametres de l'executable.
** DESCRIPTION :
**		Affiche l'usage.
** RETOUR :
**		Rien.
*/

void	usage(int ac)
{
	if (ac > 2)
		ft_putstr("Too many arguments.\n");
	ft_putstr("usage:\n./fractol [fractal name]\n");
	ft_putstr("[fractal name] has to be one of the following:\n");
	ft_putstr("Julia\nMandelbrot\nBurningShip\n");
}

/*
** FONCTION : parse_fractol
** PARAMETRES :	char **frac: le premier argument de ./fractol.
** DESCRIPTION :
**		Vérifie s'il y a un argument et s'il est dans la liste des fractales
**		disponibles.
** RETOUR :
**		-1: Si l'argument n'est pas un fractal de la liste.
**		1: Si le ou les arguments sont valide/s.
*/

int		ft_get_fractol(char *fractal, char *list_frac[NB_FRACTAL + 1])
{
	int			i;

	i = 0;
	while (i < (int)NB_FRACTAL)
	{
		if (ft_strcmp(fractal, list_frac[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/*
** FONCTION: FRACTL_PTR_ASSOCIATION
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

void	fractal_ptr_association(t_mlx *mlx)
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
** FUNCTION: main
** PARAMETRES:
**		ac [int]: le nombre d'arguments a l'execution.
**		av [char**]: tableau de string (les arguments).
** DESCRIPTION:
**		Fractol est un programme qui permet de visualiser 3 fractales
**		différents: Julia, Mandelbrot et Burning ship.
*/

int		main(int ac, char **av)
{
	int			index;
	static char	*list_frac[NB_FRACTAL + 1] = {FRACTAL1,
											FRACTAL2,
											FRACTAL3,
											FRACTAL4,
											NULL};

	index = 0;
	if (ac != 2 || (index = ft_get_fractol(av[1], list_frac)) == -1)
	{
		usage(ac);
		return (0);
	}
	if (ft_mlx(list_frac[index]) == 0)
		return (0);
	return (0);
}
