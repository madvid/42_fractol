/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:35:33 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:34:57 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

/*
** FONCTION : ft_parse_chek
** PARAMETRES :	char *av: un argument parmi ceux donné à ./fractol.
**				char **list_frac: liste des fractales disponible.
** DESCRIPTION :
**		Vérifie que l'argument donné est le nom d'un fractale disponible
** RETOUR :
**		0: Si l'argument n'est pas un fractale de la liste.
**		1: Si l'argument appartient à la liste des fractales.
*/

int	check_arg(char *av, char **list_frac)
{
	int			i;
	int			ret;

	i = -1;
	ret = -1;
	while (list_frac[++i] && ret == -1)
		ret = ft_int_tern(ft_strcmp(av, list_frac[i]) != 0, -1, i);
	return (ret);
}
