/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:51:13 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/09 02:02:33 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"
#include "libft.h"

/*
** FONCTION : mlx_win_img
** PARAMETRES : mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
**				gdad [t_gdad*]: gdad 
** DESCRIPTION :
**		Initialises pointers and variables of the mlx and img structures.
** RETOUR :
**		None.
*/

void	mlx_win_img(t_mlx *mlx, t_gdad *gdad)
{
	mlx->w_ptr = mlx_new_window(mlx->init, W_LX, W_LY, NAME);
	mlx->w_title = NAME;
	mlx->w_lx = W_LX;
	mlx->w_ly = W_LY;
	mlx->f_color = colorscale_viridis;
	mlx->img = (t_img *)malloc(sizeof(t_img));
	if (!(mlx->img))
		ft_close(mlx);
	mlx->img->ptr = mlx_new_image(mlx->init, IMG_LX, IMG_LY);
	mlx->img->pixels = (unsigned int *)mlx_get_data_addr(mlx->img->ptr,
			&(gdad->bpp), &(gdad->s_l), &(gdad->edian));
	mlx->img->nb_c = IMG_LX;
	mlx->img->nb_l = IMG_LY;
	mlx->img->ratio = ASPECT_RATIO;
	mlx->img->origin.x = 0;
	mlx->img->origin.y = 0;
	mlx->img->cst.x = CST_X;
	mlx->img->cst.y = CST_Y;
	mlx->img->root1 = (t_ldpt){1, 0, 0};
	mlx->img->root2 = (t_ldpt){-0.5, sqrtl(3) / 2.0, 0};
	mlx->img->root3 = (t_ldpt){-0.5, -sqrtl(3) / 2.0, 0};
	mlx->img->degree = DEGREE;
	mlx->img->nb_iter = MAX_ITER;
}

/*
** FONCTION : mlx_hook_loop
** PARAMETRES : mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Calls the different mlx hook functions and the mlx loop function.
** RETOUR :
**		None.
*/

void	mlx_hook_loop(t_mlx *mlx)
{
	mlx_hook(mlx->w_ptr, 2, (1L << 0), ft_key_press, mlx);
	mlx_hook(mlx->w_ptr, 3, (1L << 1), ft_key_release, mlx);
	mlx_hook(mlx->w_ptr, 6, (1L << 6), ft_mouse_move, mlx);
	mlx_mouse_hook(mlx->w_ptr, ft_mouse_event, mlx);
	mlx_hook(mlx->w_ptr, 17, (1L << 17), ft_close, mlx);
	mlx_loop(mlx->init);
}

/*
** FONCTION : ft_close
** PARAMETRES :
**		mlx [t_mlx*]: pointer the struct wrapping mlx/img variables
** DESCRIPTION :
**		Free all allocates memories and leave the program.
** RETOUR :
**		None.
*/

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img->ptr);
	free(mlx->img);
	mlx->img = NULL;
	free(mlx);
	mlx = NULL;
	exit(0);
}

/*
** FONCTION: mlx_put_header
** PARAMETRES:
** DESCRIPTION:
**	Displays the different string for the header
** RETOUR:
**		None
*/

void	mlx_put_header(t_mlx *mlx)
{
	int		white;

	white = ft_rgb2_to_int((t_rgb){254, 254, 254});
	mlx_string_put(mlx->init, mlx->w_ptr, FCL_X, TXT_Y, white, mlx->img->fractal);
	mlx_string_put(mlx->init, mlx->w_ptr, MD_X, TXT_Y, white, "mdavid");
	mlx_string_put(mlx->init, mlx->w_ptr, HLP_X, TXT_Y, white, "press H for help");
}

/*
** FONCTION: ft_mlx
** PARAMETRES:
**		frac [char*]: fractal name received as program parameter
** DESCRIPTION:
**		Calls the initialization process, the association fractal function
**		the first fractal construction and the hooks and loop function. 
** RETOUR:
**		0: no particular behavior expected, returned value is managed in
**		   main function.
*/

int	ft_mlx(char *frac)
{
	t_mlx	*mlx;
	t_gdad	gdad;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx->init = mlx_init();
	mlx_win_img(mlx, &gdad);
	mlx->img->fractal = frac;
	fractal_ptr_association(mlx);
	fractal_construct(mlx);
	mlx_put_header(mlx);
	mlx_put_image_to_window(mlx->init, mlx->w_ptr, mlx->img->ptr, 0, W_LY / 10);
	mlx_hook_loop(mlx);
	return (0);
}
