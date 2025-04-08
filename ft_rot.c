/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:03:38 by adiri             #+#    #+#             */
/*   Updated: 2025/01/05 10:13:26 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_iso(t_data *d, t_rot_iso *rot, int i, int j)
{
	rot->x = d->p[i][j]->x;
	rot->y = d->p[i][j]->y;
	rot->z = d->p[i][j]->z * d->dp;
	rot->y1 = rot->cy * rot->y - rot->sy * rot->z;
	rot->z1 = rot->sy * rot->y + rot->cy * rot->z;
	rot->x2 = rot->cx * rot->x + rot->sx * rot->z1;
	rot->z2 = -rot->sx * rot->x + rot->cx * rot->z1;
	rot->x3 = rot->cz * rot->x2 - rot->sz * rot->y1;
	rot->y3 = rot->sz * rot->x2 + rot->cz * rot->y1;
	rot->xx = (rot->x3 - rot->y3) * rot->c_angle;
	rot->yy = -rot->z2 + (rot->x3 + rot->y3) * rot->s_angle;
	rot->xx *= d->z;
	rot->yy *= d->z;
}

void	ft_rot_pres(t_data *d, t_rot_pres *rot, int i, int j)
{
	rot->x = d->p[i][j]->x;
	rot->y = d->p[i][j]->y;
	rot->z = d->p[i][j]->z * d->dp;
	rot->y1 = rot->y * rot->cx - rot->z * rot->sx;
	rot->z1 = rot->y * rot->sx + rot->z * rot->cx;
	rot->x2 = rot->x * rot->cy + rot->z1 * rot->sy;
	rot->z2 = -rot->x * rot->sy + rot->z1 * rot->cy;
	rot->x_rot = rot->x2 * rot->cz - rot->y1 * rot->sz;
	rot->y_rot = rot->x2 * rot->sz + rot->y1 * rot->cz;
	if (rot->z2 + d->z <= 0.1)
		rot->z2 = 0.1 - d->z;
	rot->f = 1;
	rot->xx = rot->f * rot->x_rot / (rot->z2 + d->z);
	rot->yy = rot->f * rot->y_rot / (rot->z2 + d->z);
	rot->h = 2 * rot->f * tan(M_PI / 6);
	rot->w = rot->h * WIDTH / HEIGHT;
}

void	ft_isometric(t_data *d)
{
	t_rot_iso	rot;
	int			j;
	int			i;

	rot.angle = M_PI / 6;
	rot.c_angle = cos(rot.angle);
	rot.s_angle = sin(rot.angle);
	rot.cx = cos(d->r_x);
	rot.sx = sin(d->r_x);
	(1) && (rot.cy = cos(d->r_y), rot.sy = sin(d->r_y));
	(1) && (rot.cz = cos(d->r_z), rot.sz = sin(d->r_z));
	i = 0;
	while (i < d->c_line)
	{
		j = 0;
		while (j < d->len_line)
		{
			ft_rot_iso(d, &rot, i, j);
			d->p[i][j]->xx = rot.xx + WIDTH / 2 + d->tx;
			d->p[i][j]->yy = rot.yy + HEIGHT / 2 + d->ty;
			j++;
		}
		i++;
	}
	ft_draw(d);
}

void	ft_perspective(t_data *d)
{
	t_rot_pres	rot;
	int			j;
	int			i;

	i = 0;
	while (i < d->c_line)
	{
		j = 0;
		while (j < d->len_line)
		{
			rot.cx = cos(d->r_x);
			rot.sx = sin(d->r_x);
			rot.cy = cos(d->r_y);
			rot.sy = sin(d->r_y);
			rot.cz = cos(d->r_z);
			rot.sz = sin(d->r_z);
			ft_rot_pres(d, &rot, i, j);
			d->p[i][j]->xx = (rot.xx / rot.w + 1) * WIDTH / 2 + d->tx;
			d->p[i][j]->yy = (1 - (rot.yy / rot.h)) * HEIGHT / 2 + d->ty;
			j++;
		}
		i++;
	}
	ft_draw(d);
}

int	ft_show_map(t_data *d)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	d->img_intro = mlx_xpm_file_to_image(d->mlx, "fdf_intro.xpm", &h, &w);
	mlx_put_image_to_window(d->mlx, d->win, d->img_intro, 0, 0);
	return (0);
}
