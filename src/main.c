/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:52:39 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/18 13:36:46 by mdavid           ###   ########.fr       */
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
	ft_putstr("Julia\nMandelbrot\n____\n");
}

/*
** FONCTION : ft_usage
** PARAMETRES :	Rien
** DESCRIPTION :
**		Affiche l'usage.
** RETOUR :
**		Rien.
*/

void	ft_fill_list_frac(char **list_frac)
{
	list_frac[0]="Julia";
	list_frac[1]="Mandelbrot";
	list_frac[2]="_____";
	list_frac[3]=NULL;
}

/*
** FONCTION : ft_parse_fractol
** PARAMETRES :	char **frac: le premier argument de ./fractol.
** DESCRIPTION :
**		Vérifie s'il y a un argument et s'il est dans la liste des fractales
**		disponible.
** RETOUR :
**		0: Si le ou les arguments ne sont pas valide/s.
**		1: Si le ou les arguments sont valide/s.
*/

int		ft_parse_fractol(int ac, char **av, char **list_frac)
{
	int			i;
	static int	ret;

	i = 0;
	while (++i < ac && ret == 0)
	{
		ret = ft_check_arg(av[i], list_frac);
		printf(">> ft_parse_fractol -- valeur de ret = %d\n", ret);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	char	*list_frac[4];

	ft_fill_list_frac(list_frac);
	if (ac == 1 || ft_parse_fractol(ac, av, list_frac) == -1)
	{
		ft_usage(ac);
		return (0);
	}
	if (ft_mlx(av[1]) == 0)
		return (0);
	return (0);
}