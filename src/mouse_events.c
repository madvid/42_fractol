/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:59:29 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 16:35:25 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION : MOUSE_EVENT
** PARAMETRES :	mcode [int]: keycode of the pressed mouse button
**				mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Manages the events associated with the mouse buttons.
** RETOUR :
**		0 : No specific operation is expected here, returns complies with the
**			prototype of the function.
*/

int	ft_mouse_event(int mcode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if ((mcode == SCROLL_UP) || (mcode == SCROLL_DOWN))
		event_zoom(ft_int_tern(mcode == SCROLL_UP, -1, 1), mlx);
	return (0);
}

/*
** FONCTION : event_zoom
** PARAMETRES :	sign [int]: -1/1 allows to increase/decrease ratio of img by
**							10% of its current value.
**				mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Applies a zoom or unzoom operation.
** RETOUR :
**		None.
*/

void	event_zoom(int sign, t_mlx *mlx)
{
	mlx->img->ratio = mlx->img->ratio * (1 + 0.1 * sign);
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}

/*
** FONCTION : FT_MOUSE_MOVE
** PARAMETRES :	mouse_x [int]: x coordinates of mouse cursor
** 				mouse_y [int]: y coordinates of mouse cursor
**				mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Manages the event associed with mouse motion.
** RETOUR :
**		0 : No specific operation is expected here, returns complies with the
**			prototype of the function.
*/

int	ft_mouse_move(int mouse_x, int mouse_y, t_mlx *mlx)
{
	mlx->img->cst.x = CST_X + 0.005 * (mouse_x - 0.5 * IMG_LX);
	mlx->img->cst.y = CST_Y + 0.005 * (mouse_y - 0.5 * IMG_LY);
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
	return (0);
}

/*
** FONCTION : key_release
** PARAMETRES : mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		No particular operation performed when releasing a button.
** RETOUR :
**		0 : No specific operation is expected here, returns complies with the
**			prototype of the function.
*/

int	ft_key_release(int kcode, t_mlx *mlx)
{
	if (kcode)
		(void)mlx;
	return (0);
}
