/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_1n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:44:07 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 14:31:35 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_1n(const char *str)
{
	size_t			i;
	size_t			len;
	char			*strcp;

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
	strcp[i] = '\n';
	strcp[i + 1] = '\0';
	return (strcp);
}
