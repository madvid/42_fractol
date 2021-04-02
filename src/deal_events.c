/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:09:28 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/02 22:57:28 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
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
	printf("valeur de key = %d\n", kcode);
	if (kcode == EXIT)
		ft_close(mlx);
	else if (kcode == UP || kcode == RIGHT || kcode == DOWN || kcode == LEFT
		|| kcode == A || kcode == S || kcode == D || kcode == W)
		event_transl(kcode, mlx);
	else if (kcode == PLUS || kcode == MINUS)
		event_zoom(kcode == PLUS ? -1 : 1, mlx);
	return (0);
}

/*
** FONCTION : EVENT_ZOOM
** PARAMETRES :	int sign : valeur de la touche du clavier pressée.
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Gère la translation du centre de l'image.
** RETOUR :
**		Aucun.
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
	if (kcode == A)
		mlx->img->origin.x -= 10 * mlx->img->ratio;
	if (kcode == S)
		mlx->img->origin.y += 10 * mlx->img->ratio;
	if (kcode == D)
		mlx->img->origin.x += 10 * mlx->img->ratio;
	if (kcode == W)
		mlx->img->origin.y -= 10 * mlx->img->ratio;
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
