/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:36:42 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/09 02:01:38 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

/*
** FONCTION: help_interface
** PARAMETRES: mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Constructs the help commands interface.
** RETOUR:
**		None
*/

void	help_text(t_mlx *mlx)
{
	int		white;

	white = ft_rgb2_to_int((t_rgb){254, 254, 254});
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, W_LY / 5, white, "Exit: Esc");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 40 + (W_LY / 5), white, "Reset default setting: SPACE");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 80 + (W_LY / 5), white, "Tiny translations: left|up|down|right");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 120 + (W_LY / 5), white, "Translations: Q|Z|S|D");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 160 + (W_LY / 5), white, "Colorscales (pad): 1|2|3|4|5|6|7|8");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 200 + (W_LY / 5), white, "Zoom / Unzoom (pad): +|-");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 240 + (W_LY / 5), white, "Change degree in Julia/Mandelbrot: 1 ... 6");
	mlx_string_put(mlx->init, mlx->w_ptr, W_LX / 5, 280 + (W_LY / 5), white, "Return to fractal: H");
}

/*
** FONCTION: event_help
** PARAMETRES: mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Constructs the help commands interface.
** RETOUR:
**		None
*/

void	help_interface(t_mlx *mlx)
{
	t_ipt	pt;
	int		grey;

	pt = (t_ipt){-1, -1, 0};
	grey = ft_rgb2_to_int((t_rgb){90, 90, 90});
	while (++pt.y < IMG_LY)
	{
		pt.x = -1;
		while(++pt.x < IMG_LX)
			mlx->img->pixels[mlx->img->nb_c * pt.y + pt.x] = grey;
	}
}

/*
** FONCTION: event_help
** PARAMETRES: mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Displays or removes the help commands interface.
** RETOUR:
**		None
*/

void	event_help(int kcode, t_mlx *mlx, int *help_lock)
{
	if (kcode == HELP && *help_lock == 1)
	{
		*help_lock = 0;
		fractal_construct(mlx);
		mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
	}
	else if (kcode == HELP && *help_lock == 0)
	{
		*help_lock = 1;
		help_interface(mlx);
		mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
		help_text(mlx);
	}
}
