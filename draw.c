/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:32:00 by adiri             #+#    #+#             */
/*   Updated: 2025/01/05 09:55:42 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_data *d)
{
	int		i;
	int		j;
	t_index	in;

	i = 0;
	while (i < d->c_line)
	{
		j = 0;
		while (j < d->len_line)
		{
			if (ft_cheak_pixel(d, i, j))
				ft_update_xy(d, &in, i, j);
			j++;
		}
		i++;
	}
	if (i == d->c_line - 1)
		ft_draw_end(d, i);
}

void	ft_draw_end(t_data *d, int i)
{
	int		j;
	t_index	in;

	j = 0;
	(1) && (in.x0 = d->p[i][j]->xx, in.y0 = d->p[i][j]->yy);
	in.c0 = d->p[i][j]->c;
	if (d->c_line == 1 && d->len_line == 1)
	{
		(1) && (in.x1 = d->p[i][j]->xx + 1, in.y1 = d->p[i][j]->yy);
		(1) && (in.c1 = d->p[i][j]->c, ft_draw_line(&in, d), j = 0);
	}
	else
	{
		while (j < d->len_line - 1)
		{
			(1) && (in.x0 = d->p[i][j]->xx, in.y0 = d->p[i][j]->yy);
			in.c0 = d->p[i][j]->c;
			(1) && (in.x1 = d->p[i][j + 1]->xx, in.y1 = d->p[i][j + 1]->yy);
			(1) && (in.c1 = d->p[i][j + 1]->c, ft_draw_line(&in, d), j++);
		}
	}
}

void	ft_draw_line(t_index *in, t_data *d)
{
	t_dr	draw;

	(1) && (draw.dx = labs(in->x0 - in->x1), draw.dy = labs(in->y0 - in->y1));
	draw.sx = ft_dir(in->x0, in->x1);
	(1) && (draw.sy = ft_dir(in->y0, in->y1), draw.err = draw.dx - draw.dy);
	(1) && (draw.r = (in->c0 >> 16) & 0xFF, draw.b = in->c0 & 0xFF);
	(1) && (ft_d(&draw, in), draw.g = (in->c0 >> 8) & 0xFF);
	while (in->x0 != in->x1 || in->y0 != in->y1)
	{
		draw.p_i = (in->y0 * d->s_l) + (in->x0 * (d->bpp / 8));
		draw.c = ft_color(draw.r, draw.g, draw.b);
		if (in->x0 >= 0 && in->x0 < WIDTH && in->y0 >= 0 && in->y0 < HEIGHT)
			*(unsigned int *)(d->data + draw.p_i) = draw.c;
		(1) && (draw.r += draw.dr, draw.g += draw.dg, draw.b += draw.db);
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.dy)
			(1) && (draw.err -= draw.dy, in->x0 += draw.sx);
		if (draw.e2 < draw.dx)
		{
			draw.err += draw.dx;
			in->y0 += draw.sy;
		}
	}
}

int	ft_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_d(t_dr *c, t_index *in)
{
	t_c	color;

	color.r_s = (in->c0 >> 16) & 0xFF;
	color.g_s = (in->c0 >> 8) & 0xFF;
	color.b_s = in->c0 & 0xFF;
	color.r_e = (in->c1 >> 16) & 0xFF;
	color.g_e = (in->c1 >> 8) & 0xFF;
	color.b_e = in->c1 & 0xFF;
	if (c->dx > c->dy)
		color.steps = c->dx;
	else
		color.steps = c->dy;
	if (color.steps == 0)
	{
		c->dr = 0;
		c->dg = 0;
		c->db = 0;
		return ;
	}
	c->dr = (color.r_e - color.r_s) / color.steps;
	c->dg = (color.g_e - color.g_s) / color.steps;
	c->db = (color.b_e - color.b_s) / color.steps;
}
