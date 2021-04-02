/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:52:39 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/02 02:14:48 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fractol.h"

/*
** FONCTION : ft_usage
** PARAMETRES :	int ac: nb de parametres de l'executable.
** DESCRIPTION :
**		Affiche l'usage.
** RETOUR :
**		Rien.
*/

void	ft_usage(int ac)
{
	if (ac > 2)
		ft_putstr("Too many arguments.\n");
	ft_putstr("usage:\n./fractol [fractal name]\n");
	ft_putstr("[fractal name] has to be one of the following:\n");
	ft_putstr("Julia\nMandelbrot\nBurningShip\n");
}

/*
** FONCTION : ft_parse_fractol
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
** FUNCTION: main
** PARAMETRES:
**		ac: (int) le nombre d'arguments a l'execution.
**		av: (char**) tableau de string (les arguments).
** Description:
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
		ft_usage(ac);
		return (0);
	}
	if (ft_mlx(list_frac[index]) == 0)
		return (0);
	return (0);
}
