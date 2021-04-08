/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:50:16 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 15:17:10 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrunc_x(char *str, size_t x)
{
	char	*trunc;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL || len <= x)
		trunc = NULL;
	else
	{
		trunc = (char *)malloc(sizeof(char) * (len - x + 1));
		if (!trunc)
			return (NULL);
		while (i + x < len)
		{
			trunc[i] = str[i];
			i++;
		}
		trunc[i] = '\0';
	}
	return (trunc);
}
