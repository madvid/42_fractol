/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:09:44 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 15:01:54 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*strnew;

	strnew = (char *)malloc(sizeof(char) * (size + 1));
	if (!strnew)
		return (NULL);
	ft_memset(strnew, '\0', size + 1);
	return (strnew);
}
