/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_managements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:29:01 by mdavid            #+#    #+#             */
/*   Updated: 2021/02/13 15:25:54 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "fractol.h"

typedef struct	s_thd_ag
{
	t_ipt			p;
	t_img			*img;
	int				(*f_frac)(t_img *img, t_fpt coord);
}				t_thd_ag;

void		*f_pack_thd_args(t_ipt *p, t_img *img, int (*f_frac)(t_img *img, t_fpt coord))
{
	t_thd_ag	*thd_ag;

	if (!(thd_ag = (t_thd_ag*)malloc(sizeof(t_thd_ag))))
		return (0);
	thd_ag->p = *p;
	thd_ag->p.x = -1;
	thd_ag->p.y = p->y;
	thd_ag->p.z = 0;
	thd_ag->img = img;
	thd_ag->f_frac = f_frac;
	return ((void*)thd_ag);
}

void		f_thd(void *thd_args)
{
	t_ipt	p;
	t_img	*img;
	t_fpt	coordc;

	p = ((t_thd_ag*)thd_args)->p;
	img = ((t_thd_ag*)thd_args)->img;
	while (++(p.x) < IMG_LX)
		{
			coordc = associated_complex_coord(p);
			p.z = ((t_thd_ag*)thd_args)->f_frac(img, coordc);
			img->pixels[img->nb_c * p.y + p.x] = ft_viridis(p.z);
		}
}