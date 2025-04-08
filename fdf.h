/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:47:49 by adiri             #+#    #+#             */
/*   Updated: 2025/01/05 10:35:38 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1080
# define WIDTH 1920
# define BUFFER 200
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"

typedef struct s_index
{
	long	x0;
	long	y0;
	long	x1;
	long	y1;
	long	c0;
	long	c1;
}	t_index;

typedef struct s_draw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		m;
	int		err;
	int		e2;
	int		p_i;
	double	dr;
	double	dg;
	double	db;
	double	r;
	double	g;
	double	b;
	int		c;
}	t_dr;	

typedef struct s_rot
{
	double	angle;
	double	c_angle;
	double	s_angle;
	double	cx;
	double	sx;
	double	cy;
	double	sy;
	double	cz;
	double	sz;
	double	x;
	double	y;
	double	z;
	double	y1;
	double	z1;
	double	x2;
	double	z2;
	double	x3;
	double	y3;
	double	xx;
	double	yy;
}	t_rot_iso;

typedef struct s_rot_pres
{
	double	cx;
	double	sx;
	double	cy;
	double	sy;
	double	cz;
	double	sz;
	double	x;
	double	y;
	double	z;
	double	y1;
	double	z1;
	double	x2;
	double	z2;
	double	x_rot;
	double	y_rot;
	double	f;
	double	xx;
	double	yy;
	double	h;
	double	w;

}	t_rot_pres;

typedef struct s_color
{
	int	r_s;
	int	g_s;
	int	b_s;
	int	r_e;
	int	g_e;
	int	b_e;
	int	steps;
}	t_c;

typedef struct s_p
{
	int		z;
	int		x;
	int		y;
	int		c;
	double	zz;	
	long	xx;
	long	yy;
}	t_p;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		len_line;
	int		c_line;
	char	*filename;
	int		pp;
	double	z;
	double	tx;
	double	ty;
	double	dp;
	int		k;
	double	r_y;
	double	r_x;
	double	r_z;
	int		bpp;
	int		s_l;
	int		f;
	int		endian;
	void	*img;
	void	*img_intro;
	char	*data;
	t_p		***p;
}	t_data;

//------------- utils functions -------------------
long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_error(char *str);
int		ft_count_line(t_data *data);
int		ft_count(char *str, int c);
int		ft_is_hex(char c);
int		ft_get_index(char c);
int		ft_count_par(char *str);
int		ft_get_hex(char *s);
int		ft_get_color(char *str);
int		ft_cheak_pixel(t_data *d, int i, int j);
void	ft_cheak(t_data *data);

//------------- free functions --------------------
void	ft_free_points(t_data *data);
void	ft_f_this(t_data *data, t_p ***p, int n, char **sp);
void	ft_free_arr(char **arr);
int		ft_close(t_data *data);

//------------- full data --------------------------
void	ft_full_point(t_data *data, char **arr);
void	ft_full_x(t_data *data, t_p ***x, char **arr, int z);
void	ft_is_clear(t_data *data, char **arr);
char	**ft_full_array(t_data *data, int c_line);
void	ft_full_data(t_data *data, char **av);
void	ft_update_xy(t_data *d, t_index *in, int i, int j);
void	ft_reinitialize_data_iso(t_data *data);
void	ft_reinitialize_data_pers(t_data *data);

//------------ windows mange -------------------------
void	ft_get_win(t_data *data);
void	ft_get_mlx(t_data *data);
void	ft_use_windows(t_data *d);
int		ft_mouse(int k, int x, int y, t_data *d);
void	ft_full_button(int k, t_data *d);
int		ft_show_map(t_data *d);

//------------ draw pixel ----------------------------
void	ft_draw(t_data *d);
void	ft_draw_line(t_index *in, t_data *d);
void	ft_draw_end(t_data *d, int i);
void	ft_d(t_dr *draw, t_index *in);
int		ft_dir(int n0, int n1);
int		ft_color(int r, int g, int b);

//------------ projections ---------------------------
void	ft_isometric(t_data *d);
void	ft_perspective(t_data *d);

#endif
