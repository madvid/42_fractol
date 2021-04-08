/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_1sp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:41:42 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:21:02 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_1sp(char const *s1, char const *s2)
{
	size_t			i;
	t__dbl_size_t	lens;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	lens = (t__dbl_size_t){ft_strlen(s1), ft_strlen(s2)};
	str = (char *)malloc(sizeof(char) * (lens.i + lens.j + 2));
	if (!str)
		return (NULL);
	while (i + 1 <= lens.i)
	{
		str[i] = s1[i];
		i++;
	}
	while (i + 1 <= lens.i + lens.j)
	{
		str[i] = s2[i - lens.i];
		i++;
	}
	str[i] = ' ';
	str[i + 1] = '\0';
	return (str);
}
