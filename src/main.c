/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:52:39 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 09:49:54 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fractol.h"

/*
** FONCTION : usage
** PARAMETRES :	ac [int]: number of parameters at the execution
** DESCRIPTION :
**		Prints the usage of the program.
** RETOUR :
**		None.
*/

int	usage(int ac)
{
	if (ac > 2)
		ft_putstr("Too many arguments.\n");
	ft_putstr("usage:\n./fractol [fractal name]\n");
	ft_putstr("[fractal name] has to be one of the following:\n");
	ft_putstr("Julia\nMandelbrot\nBurningShip\nNewton");
	return (0);
}

/*
** FONCTION : parse_fractol
** PARAMETRES :	frac [*char]: first program parameter, should be a fractal name
**				list_frac [**char]: table of available fractal name
** DESCRIPTION :
**		Checks the firs argument. The first argument should be one of the fractal
**		in the list_frac.
** RETOUR :
**		-1: if frac is not in list_frac.
**		1: if frac is in list_frac.
*/

int	ft_get_fractol(char *fractal, char *list_frac[NB_FRACTAL + 1])
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
** PARAMETRES: mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Associates the fractal function to the function pointer mlx->f_fractal
**		based on the fractal name saved in mlx->img->fractal.
** RETOUR:
***		None.
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
** DESCRIPTION:
**		Checks the number of parameters plus the value of the first parameter
**		and calls usage function if the there is more than 2 parameters or
**		if the value of the 1st parameter is not an expected value.
**		If the condition is valid, ft_mlx is called to start the process
**		leading to the display of the fractal.
*/

int	main(int ac, char **av)
{
	int			index;
	static char	*list_frac[NB_FRACTAL + 1] = {FRACTAL1,
											FRACTAL2,
											FRACTAL3,
											FRACTAL4,
											NULL};

	index = 0;
	if (ac != 2)
		return (usage(ac));
	index = ft_get_fractol(av[1], list_frac);
	if (index == -1)
		return (usage(ac));
	if (ft_mlx(list_frac[index]) == 0)
		return (0);
	return (0);
}
