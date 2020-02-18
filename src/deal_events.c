/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:09:28 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/18 12:33:33 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "../include/fractol.h"

/*
** FONCTION : KEY_PRESS
** PARAMETRES :	int keycode : valeur de la touche du clavier pressée.
**				t_mlx *mlx : ptr général contenant les struct wind/events/img.
** DESCRIPTION :
**		Gère les événements liés au clavier.
** RETOUR :
**		0 : Aucune gestion de la valeur de retour, le prototype impose un int
**			en retour de la fct.
*/

int		ft_key_press(int keycode, t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img->ptr);
	if (keycode == 53)
		ft_close(mlx);
	/*if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_event_transl(keycode, (*mlx)->events, (*mlx)->img);
	if (keycode >= 83 && keycode <= 88)
		ft_rotation_xyz(keycode, mlx, (*mlx)->events, (*mlx)->img);
	if (keycode == 24 || keycode == 27)
		ft_altitude(keycode, mlx, (*mlx)->events, (*mlx)->img);
	if (keycode == 69 || keycode == 78)
		ft_zoom(keycode, mlx, (*mlx)->events, (*mlx)->img);
	if (keycode == 34 || keycode == 35)
		ft_projections(keycode, mlx, (*mlx)->events, (*mlx)->img);
	ft_display_map(*mlx, (*mlx)->img);*/
	return (0);
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

int		ft_key_release(int keycode, t_mlx *mlx)
{
	if (keycode)
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

/*int		ft_mouse_event(int button, int x, int y, t_mlx *mlx)
{
	int		sign;
	int		nu;
	int		i;

	sign = 0;
	nu = 1;
	i = 8;
	if (button == 1)
	{
		if (x >= WIN_LX / 142 && x <= WIN_LX / 142 + 30)
			sign = -1;
		if (x >= WIN_LX / 42 && x <= WIN_LX / 42 + 30)
			sign = 1;
		while (nu < 8)
		{
			if (sign != 0 && (y >= i * WIN_LY / 48 && y <= i * WIN_LY / 48
			+ 20))
				break ;
			i = i + 5;
			nu++;
		}
		if (sign != 0 && nu != 8)
			ft_deal_press_button(nu, sign, mlx, mlx->events);
	}
	return (0);
}*/
