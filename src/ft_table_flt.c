/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_flt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:23:37 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/12 19:59:46 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

/*
** FONCTION : FT_FREE_TABFLT
** PARAMETRES :	float **table : tableau de float
**				int nb_l : nb de ligne.
** DESCRIPTION :
**		free le tableau passé en argument et ayant nb_l lignes.
**	RETOUR :
**		RIEN.
*/

void	ft_free_tabflt(float **table, int nb_l)
{
	if (table)
	{
		while (nb_l > 0)
		{
			free(table[nb_l - 1]);
			nb_l--;
		}
		free((void*)table);
		table = NULL;
	}
}

/*
** FONCTION : FT_TABLE_FLT_INIT.
** PARAMETRES :	float **table : tableau de float.
**				int nb_l : nb line de table.
**				int	nb_c : nb column de table.
** DESCRIPTION :
**		Initialise l'ensemble des éléments de table à 0.
** RETOUR :
**		RIEN.
*/

void	ft_table_flt_init(float **table, int nb_l, int nb_c)
{
	int		k;
	int		l;

	k = 0;
	while (k < nb_l)
	{
		l = 0;
		while (l < nb_c)
		{
			table[k][l] = 0.00000;
			l++;
		}
		k++;
	}
}

/*
** FONCTION : FT_TABLE_FLT
** PARAMETRE(S) :	int nb_l : nb de lignes.
**					int nb_c : nb de colonnes.
** DESCRIPTION :
**	Allocation d'un tableau de float de la taille (nb_c x nb_l) d'un tetramino.
**	Ce tableau permet de compter le nombre de blocs voisins du bloc considéré.
**	La condition pour que le tetramino soit valide est que la somme des entiers
**	présent dans le tableau soit au moins de 6.
** RETOUR :
**	NULL s'il y a eu une erreur lors de l'allocation.
**	un tableau de INT initialisé à 0 sinon.
*/

float	**ft_table_flt(int nb_l, int nb_c)
{
	float		**table;
	int			i;

	i = 0;
	if (!(table = (float**)malloc(sizeof(float*) * nb_l)))
		return (NULL);
	while (i < nb_l)
	{
		if (!(table[i] = (float*)malloc(sizeof(float) * nb_c)))
		{
			while (--i >= 0)
				free(table[i]);
			free(table);
			return (NULL);
		}
		i++;
	}
	ft_table_flt_init(table, nb_l, nb_c);
	return (table);
}
