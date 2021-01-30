/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:20:00 by mdavid            #+#    #+#             */
/*   Updated: 2021/01/30 15:41:41 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		mlx->img->origin.x = 2 * (keycode - 123) - 1;
	else
		mlx->img->origin.y = 1 - 2 * (keycode -125);
	julia(mlx->img);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0
	, W_LY / 10);
}