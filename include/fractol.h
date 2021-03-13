/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:23:23 by mdavid            #+#    #+#             */
/*   Updated: 2021/03/13 15:58:54 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define NAME "fractol"
# define W_LX 800
# define W_LY 800
# define IMG_LX W_LX
# define IMG_LY W_LY
# define NB_FRACTAL 4
# define FRACTAL1 "Julia"
# define FRACTAL2 "Mandelbrot"
# define FRACTAL5 "BurningShip"
# define FRACTAL6 "Newton"
# define CST_X 0.0
# define CST_Y 0.0
# define DEG_MANDELBROT 1
# define ASPECT_RATIO 1
# define RADIUS 2
# define MAX_ITER 98

// Definition des valeurs pour les evenements
// Clavier
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define A 0
# define S 1
# define D 2
# define W 13

// Souris
# define M_LEFT 1
# define M_RIGHT 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5


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

typedef struct	s_ipt
{
	int				x;
	int				y;
	int				z;
}				t_ipt;

typedef struct	s_fpt
{
	long double	x;
	long double	y;
	long double	z;
}				t_fpt;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*pixels;
	int				nb_c;
	int				nb_l;
	char			*fractal;
	t_fpt			origin;
	t_fpt			cst;
	int				deg_mandelbrot;
	long double		ratio;
	int				nb_iter;
}				t_img;

typedef struct	s_mlx
{
	void			*init;
	void			*w_ptr;
	char			*w_title;
	int				w_lx;
	int				w_ly;
	int				(*f_fractal)(t_img *img, t_fpt coord);
	int				(*f_color)(int level);
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
int		ft_mouse_event(int button, int x, int y, t_mlx *mlx);
void	ft_event_transl(int kcode, t_mlx *mlx);
int		ft_mouse_move(int mouse_x, int mouse_y, t_mlx *mlx);

int		ft_close(t_mlx *mlx);
void	ft_mlx_win_img(t_mlx *mlx, t_gdad *gdad);
void	ft_mlx_hook(t_mlx *mlx);

// Fonctions en lien avec la gestion des différents fractales //
void	fractal_construct(t_mlx *mlx);
void	ft_fractal(t_mlx *mlx);
int		julia(t_img *img, t_fpt coordc);
int		mandelbrot(t_img *img, t_fpt coordc);
int		mandelbrot2(t_img *img, t_fpt coordc);
int		mandelbrot3(t_img *img, t_fpt coordc);
int		burningship(t_img *img, t_fpt coordc);

// Fonctions en lien avec les aspects de couleurs du projet //
t_rgb	ft_hsv_to_rgb(t_hsv hsv);
t_hsv	ft_rgb_to_hsv(int red, int green, int blue);
int		ft_rgb2_to_int(t_rgb rgb);
int		ft_rgb_to_int(int red, int green, int blue);
int		colorscale_viridis(int level);
int		colorscale_magma(int level);
int		colorscale_ylorbr(int level);
int		colorscale_mako(int level);
int		colorscale_coolwarm(int level);
int		colorscale_reds(int level);
int		colorscale_greens(int level);
int		colorscale_blues(int level);
int		f_cborn(double value);

// Fonctions en lien avec les aspects mathematiques du projet //
t_fpt	associated_complex_coord(t_ipt p, t_img *img);
t_fpt	complex_prod(t_fpt z1, t_fpt z2)

void	f_thd(void *ptr);

#endif