/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:53:03 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 14:15:31 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t n)
{
	void	*tab;

	tab = malloc(n);
	if (!tab)
		return (NULL);
	ft_bzero(tab, n);
	return (tab);
}
