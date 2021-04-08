/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternaries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:03:24 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:21:37 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FONCTION: ft_flt_tern
** PARAMETRES: condition [int/bool]: result of a condition
**			   val1 [float]: float value if condition is True
**			   val2 [float]: float value if condition is False
** DESCRIPTION:
**		Useless function but since the new version 42school norm
**		(norminette v3), ternary operator is forbidden thus this
**		function is a wrapper to mimic ternary operator.
** RETOUR:
**		val1 [float]: returned float value if condition True
**		val2 [float]: returned float value if condition False
*/

float	ft_flt_tern(int condition, float val1, float val2)
{
	if (condition)
		return (val1);
	return (val2);
}

/*
** FONCTION: ft_int_tern
** PARAMETRES: condition [int/bool]: result of a condition
**			   val1 [int]: int value if condition is true
**			   val2 [int]: int value if condition is false
** DESCRIPTION:
**		Useless function but since the new version 42school norm
**		(norminette v3), ternary operator is forbidden thus this
**		function is a wrapper to mimic ternary operator.
** RETOUR:
**		val1 [int]: returned int value if condition True
**		val2 [int]: returned int value if condition False
*/

int	ft_int_tern(int condition, int val1, int val2)
{
	if (condition)
		return (val1);
	return (val2);
}

/*
** FONCTION: ft_uint_tern
** PARAMETRES: condition [int/bool]: result of a condition
**			   val1 [uint]: unsigned int value if condition is true
**			   val2 [uint]: unsigned int value if condition is false
** DESCRIPTION:
**		Useless function but since the new version 42school norm
**		(norminette v3), ternary operator is forbidden thus this
**		function is a wrapper to mimic ternary operator.
** RETOUR:
**		val1 [uint]: returned unsigned int value if condition True
**		val2 [uint]: returned unsigned int value if condition False
*/

unsigned int
	ft_uint_tern(int condition, unsigned int val1, unsigned int val2)
{
	if (condition)
		return (val1);
	return (val2);
}

/*
** FONCTION: ft_str_tern
** PARAMETRES: condition [int/bool]: result of a condition
**			   val1 [str]: str value if condition is true
**			   val2 [str]: str value if condition is false
** DESCRIPTION:
**		Useless function but since the new version 42school norm
**		(norminette v3), ternary operator is forbidden thus this
**		function is a wrapper to mimic ternary operator.
** RETOUR:
**		val1 [str]: returned str value if condition True
**		val2 [str]: returned str value if condition False
*/

char	*ft_str_tern(int condition, char *val1, char *val2)
{
	if (condition)
		return (val1);
	return (val2);
}
