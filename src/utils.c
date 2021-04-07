/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:03:24 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/07 21:52:34 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**
**
**
*/

float flt_tern(int condition, float val1, float val2)
{
	if (condition)
		return val1;
	else
		return val2;
}

/*
**
**
**
*/

int int_tern(int condition, int val1, int val2)
{
	if (condition)
		return val1;
	else
		return val2;
}
