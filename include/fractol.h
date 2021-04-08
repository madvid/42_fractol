/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:23:23 by mdavid            #+#    #+#             */
/*   Updated: 2021/04/08 23:42:14 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define NAME "Frac'tol"
# define W_LX 500
# define W_LY 500
# define IMG_LX W_LX
/*
** Due to norm v3 of 42school define based on other defines are not allowed
** If modification are made on W_LX and W_LY, it is necessary to recalculate
** IMG_LY, TXT_Y, MD_X, FCL_X and HLP_X
*/
/* # define IMG_LY 9 * W_LY / 10
** # define TXT_Y W_LY / 20
** # define MD_X 90 * W_LX / 100
** # define FCL_X 20 *  W_LX / 50
** # define HLP_X W_LX / 100
*/
# define IMG_LY 450
# define TXT_Y 25
# define MD_X 450
# define FCL_X 200
# define HLP_X 5
# define NB_FRACTAL 4
# define FRACTAL1 "Julia"
# define FRACTAL2 "Mandelbrot"
# define FRACTAL3 "BurningShip"
# define FRACTAL4 "Newton"
# define CST_X 0.0
# define CST_Y 0.0
# define DEGREE 2
# define DEG_LIM 3
# define ASPECT_RATIO 0.008
# define RADIUS 4
# define MAX_ITER 99
# define FT_DBL_MIN 2.225074e-308
# define FT_DBL_MAX 1.797693e+308

// Definition des valeurs pour les evenements
// Keyboard
# if defined(__APPLE__)
#  define EXIT 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define A 0
#  define S 1
#  define D 2
#  define W 13
#  define HELP 4
#  define SPACE 49
#  define PAD_ONE 83
#  define PAD_TWO 84
#  define PAD_THREE 85
#  define PAD_FOUR 86
#  define PAD_FIVE 87
#  define PAD_SIX 88
#  define PAD_SEVEN 89
#  define PAD_EIGHT 90
#  define PAD_PLUS 69
#  define PAD_MINUS 78
#  define ONE 18
#  define TWO 19
#  define THREE 20
#  define FOUR 21
#  define FIVE 23
#  define SIX 22
# elif defined(__linux__)
#  define EXIT 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define Z 122
#  define S 115
#  define D 100
#  define Q 113
#  define HELP 104
#  define SPACE 32
#  define PAD_ONE 65436
#  define PAD_TWO 65433
#  define PAD_THREE 65435
#  define PAD_FOUR 65430
#  define PAD_FIVE 65437
#  define PAD_SIX 65432
#  define PAD_SEVEN 65429
#  define PAD_EIGHT 65431
#  define PAD_PLUS 65451
#  define PAD_MINUS 65453
#  define ONE 38
#  define TWO 233
#  define THREE 34
#  define FOUR 39
#  define FIVE 40
#  define SIX 45
# endif

// Souris
# define M_LEFT 1
# define M_RIGHT 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef struct s_hsv
{
	float	h;
	float	s;
	float	v;
}				t_hsv;

typedef struct s_ipt
{
	int				x;
	int				y;
	int				z;
}				t_ipt;

typedef struct s_ldpt
{
	long double	x;
	long double	y;
	long double	z;
}				t_ldpt;

typedef struct s_img
{
	void			*ptr;
	unsigned int	*pixels;
	int				nb_c;
	int				nb_l;
	char			*fractal;
	t_ldpt			origin;
	t_ldpt			cst;
	t_ldpt			root1;
	t_ldpt			root2;
	t_ldpt			root3;
	int				degree;
	long double		ratio;
	int				nb_iter;
}				t_img;

typedef struct s_mlx
{
	void			*init;
	void			*w_ptr;
	char			*w_title;
	int				w_lx;
	int				w_ly;
	int				(*f_fractal)(t_img *img, t_ldpt coord);
	int				(*f_color)(int level);
	t_img			*img;
}				t_mlx;

typedef struct s_gdad
{
	int				bpp;
	int				s_l;
	int				edian;
}				t_gdad;

int			parse_fractol(int ac, char **av, char **list_frac);
void		fill_list_frac(char **list_frac);
int			usage(int ac);
int			check_arg(char *frac, char **list_frac);
int			ft_mlx(char *frac);

int			ft_key_press(int keycode, t_mlx *mlx);
int			ft_key_release(int keycode, t_mlx *mlx);
int			ft_mouse_event(int button, int x, int y, t_mlx *mlx);
void		event_transl(int kcode, t_mlx *mlx);
void		event_zoom(int sign, t_mlx *mlx);
void		event_color(int color_code, t_mlx *mlx);
void		modify_degree(int kcode, t_mlx *mlx);
void		reset_parameters(t_mlx *mlx);
void		event_help(t_mlx *mlx, int *help_lock);
void		help_interface(t_mlx *mlx);
void		help_text(t_mlx *mlx);
int			ft_mouse_move(int mouse_x, int mouse_y, t_mlx *mlx);

int			ft_close(t_mlx *mlx);
void		mlx_put_header(t_mlx *mlx);
void		mlx_win_img(t_mlx *mlx, t_gdad *gdad);
void		mlx_hook_loop(t_mlx *mlx);

// Fonctions en lien avec la gestion des différents fractales //
void		fractal_ptr_association(t_mlx *mlx);
int			julia(t_img *img, t_ldpt coordc);
int			mandelbrot(t_img *img, t_ldpt coordc);
int			burningship(t_img *img, t_ldpt coordc);
int			classic_newton(t_img *img, t_ldpt coordc);
t_ldpt		formula_newton(t_ldpt z, int degree);

// Fonctions en lien avec les aspects de couleurs du projet //
t_rgb		ft_hsv_to_rgb(t_hsv hsv);
t_hsv		ft_rgb_to_hsv(int red, int green, int blue);
int			ft_rgb2_to_int(t_rgb rgb);
int			ft_rgb_to_int(int red, int green, int blue);
int			colorscale_viridis(int level);
int			colorscale_magma(int level);
int			colorscale_ylorbr(int level);
int			colorscale_mako(int level);
int			colorscale_coolwarm(int level);
int			colorscale_reds(int level);
int			colorscale_greens(int level);
int			colorscale_blues(int level);
int			f_cborn(double value);

// Fonctions en lien avec les aspects mathematiques du projet //
t_ldpt		associated_c_coord(t_ipt p, t_img *img);
t_ldpt		complex_conjugate(t_ldpt z);
t_ldpt		c_prod(t_ldpt z1, t_ldpt z2);
t_ldpt		c_power(t_ldpt z, int p);
long double	c_module(t_ldpt z);
long double	c_dist(t_ldpt z1, t_ldpt z2);

// Fonctions en lien avec le multithreading
void		fractal_construct(t_mlx *mlx);
void		f_thd1(void *ptr);
void		f_thd2(void *ptr);

#endif