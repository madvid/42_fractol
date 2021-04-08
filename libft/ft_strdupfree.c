/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:38:13 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:21:17 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdupfree(char **dest, char **src)
{
	if (*dest)
	{
		ft_strclr(*dest);
		ft_strdel(dest);
	}
	if (*src)
	{
		*dest = ft_strdup(*src);
		ft_strclr(*src);
		ft_strdel(src);
	}
	return (ft_int_tern(*dest == NULL && *src == NULL, -1, 0));
}
