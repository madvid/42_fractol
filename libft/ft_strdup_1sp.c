/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_1sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:41:44 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 15:28:34 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_1sp(const char *str)
{
	size_t	i;
	size_t	len;
	char	*strcp;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	strcp = (char *)malloc(sizeof(char) * (len + 2));
	if (!strcp)
		return (0);
	while (i < len)
	{
		strcp[i] = str[i];
		i++;
	}
	strcp[i] = ' ';
	strcp[i + 1] = '\0';
	return (strcp);
}
