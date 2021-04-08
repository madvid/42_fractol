/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:35:23 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:02:12 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	int		ret;

	ret = c;
	if (c >= 'a' && c <= 'z')
	{
		ret = c - 32;
	}
	return (ret);
}
