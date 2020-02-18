/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:23:23 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/18 17:06:32 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define NAME "fractol"
# define W_LX 1080
# define W_LY 720
# define IMG_LX W_LX
# define IMG_LY 9 * W_LY / 10

typedef struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef struct	s_hsv
{
	float	h;
	float	s;
	float	v;
}				t_hsv;

typedef struct	s_fpt
{
	float			x;
	float			y;
	float			z;
}				t_fpt;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*pixels;
	int				**i_tab;
	float			**f_tab;
	int				nb_c;
	int				nb_l;
	t_fpt			center;
}				t_img;

typedef struct	s_mlx
{
	void			*init;
	void			*w_ptr;
	char			*w_title;
	int				w_lx;
	int				w_ly;
	t_img			*img;
}				t_mlx;

typedef struct	s_gdad
{
	int				bpp;
	int				s_l;
	int				edian;
}				t_gdad;

int		ft_parse_fractol(int ac, char **av, char **list_frac);
void	ft_fill_list_frac(char **list_frac);
void	ft_usage(int ac);
int		ft_check_arg(char *frac, char **list_frac);
int		ft_mlx(char *frac);

void	ft_free_tabint(int **table, int nb_l);
void	ft_table_int_init(int **table, int nb_l, int nb_c);
int		**ft_table_int(int nb_l, int nb_c);

void	ft_free_tabflt(float **table, int nb_l);
void	ft_table_flt_init(float **table, int nb_l, int nb_c);
float	**ft_table_flt(int nb_l, int nb_c);

int		ft_key_press(int keycode, t_mlx *mlx);
int		ft_key_release(int keycode, t_mlx *mlx);
//int		ft_mouse_event(int button, int x, int y, t_mlx *mlx);

int		ft_close(t_mlx *mlx);
void	ft_mlx_win_img(t_mlx *mlx, t_gdad *gdad);
void	ft_mlx_hook(t_mlx *mlx);

int		ft_fractal(char *frac, t_img *img);
int		ft_julia(t_img *img);
int		ft_mandelbrot(t_img *img);
int		ft_julia2(t_img *img);

//t_hsv	ft_rbg_to_hsv(t_rgb rgb);
//t_hsv	ft_rbg_to_hsv(int red, int green, int blue);
int		ft_rgb_to_int(int red, int green, int blue);

#endif