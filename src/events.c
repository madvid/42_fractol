/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:20:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/19 17:36:35 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include <>
include "fractol.h"
include "libft.h"

/*
** FONCTION: ft_event_transl
** PARAMETRES:
** DESCRIPTON:
**
** RETOUR:
** 	rien.
*/

void	ft_event_transl(int keycode, t_mlx *mlx);
{
	if (keycode == 123 || keycode == 124)
		mlx->img->move.x = 2 * (keycode - 123) - 1;
	else
		mlx->img->move.y = 1 - 2 * (keycode -125);
	ft_julia(mlx->img);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0
	, W_LY / 10);
}