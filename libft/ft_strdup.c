/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:20:32 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 14:54:59 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t			i;
	size_t			len;
	char			*strcp;

	i = 0;
	len = ft_strlen(str);
	strcp = (char *)malloc(sizeof(char) * (len + 1));
	if (!strcp)
		return (0);
	while (i <= len)
	{
		strcp[i] = str[i];
		i++;
	}
	return (strcp);
}
