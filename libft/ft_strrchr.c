/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:07:29 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 15:27:22 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (*s == '\0')
		return (ft_str_tern((char)c == '\0', (char *)s, NULL));
	while (s[slen] != (char)c && slen > 0)
		slen--;
	if (slen == 0 && s[slen] == (char)c)
		return ((char *)s);
	return (ft_str_tern(slen == 0, NULL, (char *)(s + slen)));
}
