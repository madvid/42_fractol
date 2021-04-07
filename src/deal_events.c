/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:09:28 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/07 16:31:34 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION : KEY_PRESS
** PARAMETRES :	int kcode : valeur de la touche du clavier pressée.
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Gère les événements liés au clavier.
** RETOUR :
**		0 : Aucune gestion de la valeur de retour, le prototype impose un int
**			en retour de la fct.
*/

int		ft_key_press(int kcode, t_mlx *mlx)
{
	if (kcode == EXIT)
		ft_close(mlx);
	else if (kcode == UP || kcode == RIGHT || kcode == DOWN || kcode == LEFT
		|| kcode == Z || kcode == S || kcode == D || kcode == Q)
		event_transl(kcode, mlx);
	else if (kcode == PAD_PLUS || kcode == PAD_MINUS)
		event_zoom(kcode == PAD_PLUS ? -1 : 1, mlx);
	else if (kcode == PAD_ONE || kcode == PAD_TWO || kcode == PAD_THREE
		|| kcode == PAD_FOUR || kcode == PAD_FIVE || kcode == PAD_SIX
		|| kcode == PAD_SEVEN || kcode == PAD_EIGHT)
		event_color(kcode, mlx);
	else if (kcode == ONE || kcode == TWO || kcode == THREE || kcode == FOUR
		|| kcode == FIVE || kcode == SIX)
		modify_deg_mandelbrot(kcode, mlx);
	else if (kcode == SPACE)
		reset_parameters(mlx);
	return (0);
}

/*
** FONCTION: RESET_PARAMETERS
** PARAMETRE: mlx [t_mlx*]: pointer on mlx variable structure
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
	mlx->img->deg_mandelbrot = DEG_MANDELBROT;
	mlx->img->nb_iter = MAX_ITER;
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}


/*
** FONCTION: MODIFY_DEG_MANDELBROT
** PARAMETRES: kcode [int]: new value of degree for mandelbrot fractal
**			   mlx [t_mlx*]: pointer on mlx variable structure
** DESCRIPTION:
**		Modify the value of the degree for Mandelbrot fractal.
** RETOUR:
**		new_deg [int]: new value for deg_mandelbrot
*/

void	modify_deg_mandelbrot(int kcode, t_mlx *mlx)
{
	if (kcode == ONE)
		mlx->img->deg_mandelbrot = 1;
	else if (kcode == TWO)
		mlx->img->deg_mandelbrot = 2;
	else if (kcode == THREE)
		mlx->img->deg_mandelbrot = 3;
	else if (kcode == FOUR)
		mlx->img->deg_mandelbrot = 4;
	else if (kcode == FIVE)
		mlx->img->deg_mandelbrot = 5;
	else
		mlx->img->deg_mandelbrot = 6;
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}

/*
** FONCTION: EVENT_COLOR
** PARAMETRES: color_code [int]:
**			   mlx [t_mlx*]:
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
** FONCTION : EVENT_ZOOM
** PARAMETRES :	int sign : valeur de la touche du clavier pressée.
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Handles the translation events.
** RETOUR :
**		None.
*/

void event_zoom(int sign, t_mlx *mlx)
{
	mlx->img->ratio = mlx->img->ratio * (1 + 0.1 * sign);
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
}

/*
** FONCTION : FT_EVENT_TRANSL
** PARAMETRES :	int kcode : valeur de la touche du clavier pressée.
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Gère la translation du centre de l'image.
** RETOUR :
**		Aucun.
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

/*
** FONCTION : KEY_RELEASE
** PARAMETRES : t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Aucune gestion particulière lors du relâchement des touches, mais
**		nécessaire pour gérer les actions répétées si on maintien une touche.
** RETOUR :
**		0 : Aucune gestion de la valeur de retour, le prototype impose un int
**			en retour de la fct.
*/

int		ft_key_release(int kcode, t_mlx *mlx)
{
	if (kcode)
		(void)mlx;
	return (0);
}

/*
** FONCTION : MOUSE_EVENT
** PARAMETRES :	int keycode : valeur de la touche de la souris pressée.
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Gère les événements liés à la souris.
** RETOUR :
**		0 : Aucune gestion de la valeur de retour, le prototype impose un int
**			en retour de la fct.
*/

int		ft_mouse_event(int mcode, int x, int y, t_mlx *mlx)
{
	/*
	if (mcode == M_LEFT) // left click
	{
		...
	}
	if (mcode == M_RIGHT) // right click
	{
		...
	}
	*/
	(void)x;
	(void)y;
	if ((mcode == SCROLL_UP) || (mcode == SCROLL_DOWN))
		event_zoom(mcode == SCROLL_UP? -1 : 1, mlx);
	return (0);
}

/*
** FONCTION : ft_mouse_move
** PARAMETRES :	int mouse_x : coordonnees x de la souris
** 				int mouse_y : coordonnees y de la souris
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Gère les événements liés à la souris.
** RETOUR :
**		0 : Aucune gestion de la valeur de retour, le prototype impose un int
**			en retour de la fct.
*/

int		ft_mouse_move(int mouse_x, int mouse_y, t_mlx *mlx)
{
	mlx->img->cst.x = CST_X + 0.005 * (mouse_x - 0.5 * IMG_LX);
	mlx->img->cst.y = CST_Y + 0.005 * (mouse_y - 0.5 * IMG_LY);
	fractal_construct(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
	return (0);
}
