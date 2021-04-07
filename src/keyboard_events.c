/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:09:28 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/07 21:58:33 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION : ft_key_press
** PARAMETRES :	kcode [int]: keycode of the pressed keyboard button
**				mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Manages the event associed with keyboard motion:
**			- close command,
**			- translation commands,
**			- zoom commands,
**			- colorscale commands,
**			- degree modification commands,
**			- reset command,
** RETOUR :
**		0 : No specific operation is expected here, returns complies with the
**			prototype of the function.
*/

int	ft_key_press(int kcode, t_mlx *mlx)
{
	if (kcode == EXIT)
		ft_close(mlx);
	else if (kcode == UP || kcode == RIGHT || kcode == DOWN || kcode == LEFT
		|| kcode == Z || kcode == S || kcode == D || kcode == Q)
		event_transl(kcode, mlx);
	else if (kcode == PAD_PLUS || kcode == PAD_MINUS)
		event_zoom(int_tern(kcode == PAD_PLUS, -1, 1), mlx);
	else if (kcode == PAD_ONE || kcode == PAD_TWO || kcode == PAD_THREE
		|| kcode == PAD_FOUR || kcode == PAD_FIVE || kcode == PAD_SIX
		|| kcode == PAD_SEVEN || kcode == PAD_EIGHT)
		event_color(kcode, mlx);
	else if (kcode == ONE || kcode == TWO || kcode == THREE || kcode == FOUR
		|| kcode == FIVE || kcode == SIX)
		modify_degree(kcode, mlx);
	else if (kcode == SPACE)
		reset_parameters(mlx);
	return (0);
}

/*
** FONCTION: reset_parameters
** PARAMETRE: mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Reset the parameters of the vizualisation.
** RETOUR:
**		None
*/

void	reset_parameters(t_mlx *mlx)
{
	mlx->f_color = colorscale_viridis;
	mlx->img->ratio = ASPECT_RATIO;
	mlx->img->origin.x = 0;
	mlx->img->origin.y = 0;
	mlx->img->cst.x = CST_X;
	mlx->img->cst.y = CST_Y;
	mlx->img->degree = DEGREE;
	mlx->img->nb_iter = MAX_ITER;
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}

/*
** FONCTION: modify_degree
** PARAMETRES: deg [int]: new value for degree applied on complex number for
**						  concerned fractal (Julia and Mandelbrot)
**			   mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Modify the value of the degree for Mandelbrot fractal.
** RETOUR:
**		None
*/

void	modify_degree(int deg, t_mlx *mlx)
{
	if (deg == ONE)
		mlx->img->degree = 1;
	else if (deg == TWO)
		mlx->img->degree = 2;
	else if (deg == THREE)
		mlx->img->degree = 3;
	else if (deg == FOUR)
		mlx->img->degree
			= int_tern(ft_strcmp(mlx->img->fractal, "Julia") == 0, DEG_LIM, 4);
	else if (deg == FIVE)
		mlx->img->degree
			= int_tern(ft_strcmp(mlx->img->fractal, "Julia") == 0, DEG_LIM, 5);
	else
		mlx->img->degree
			= int_tern(ft_strcmp(mlx->img->fractal, "Julia") == 0, DEG_LIM, 6);
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}

/*
** FONCTION: event_color
** PARAMETRES: color_code [int]: colorscale code value
**			   mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION:
**		Modify the colorscale used to draw the fractal
** RETOUR:
**		None
*/

void	event_color(int color_code, t_mlx *mlx)
{
	if (color_code == PAD_ONE)
		mlx->f_color = colorscale_viridis;
	else if (color_code == PAD_TWO)
		mlx->f_color = colorscale_magma;
	else if (color_code == PAD_THREE)
		mlx->f_color = colorscale_ylorbr;
	else if (color_code == PAD_FOUR)
		mlx->f_color = colorscale_mako;
	else if (color_code == PAD_FIVE)
		mlx->f_color = colorscale_coolwarm;
	else if (color_code == PAD_SIX)
		mlx->f_color = colorscale_blues;
	else if (color_code == PAD_SEVEN)
		mlx->f_color = colorscale_greens;
	else
		mlx->f_color = colorscale_reds;
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}

/*
** FONCTION : event_transl
** PARAMETRES :	kcode [int]: value of the translation action pressed
**				mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Applies a translation operation.
** RETOUR :
**		None.
*/

void	event_transl(int kcode, t_mlx *mlx)
{
	if (kcode == UP)
		mlx->img->origin.y -= 1 * mlx->img->ratio;
	if (kcode == DOWN)
		mlx->img->origin.y += 1 * mlx->img->ratio;
	if (kcode == RIGHT)
		mlx->img->origin.x += 1 * mlx->img->ratio;
	if (kcode == LEFT)
		mlx->img->origin.x -= 1 * mlx->img->ratio;
	if (kcode == Z)
		mlx->img->origin.y -= 10 * mlx->img->ratio;
	if (kcode == S)
		mlx->img->origin.y += 10 * mlx->img->ratio;
	if (kcode == D)
		mlx->img->origin.x += 10 * mlx->img->ratio;
	if (kcode == Q)
		mlx->img->origin.x -= 10 * mlx->img->ratio;
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}
