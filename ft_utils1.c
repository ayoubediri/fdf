/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:51:41 by adiri             #+#    #+#             */
/*   Updated: 2025/01/05 10:15:25 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cheak_pixel(t_data *d, int i, int j)
{
	if (d->p[i][j]->xx < 0 || d->p[i][j]->xx > WIDTH)
	{
		if (d->p[i][j]->yy < 0 || d->p[i][j]->yy > HEIGHT)
			return (0);
	}
	return (1);
}

void	ft_update_xy(t_data *d, t_index *in, int i, int j)
{
	in->x0 = d->p[i][j]->xx;
	in->y0 = d->p[i][j]->yy;
	in->c0 = d->p[i][j]->c;
	if (j + 1 < d->len_line)
	{
		in->x1 = d->p[i][j + 1]->xx;
		in->y1 = d->p[i][j + 1]->yy;
		in->c1 = d->p[i][j + 1]->c;
		ft_draw_line(in, d);
	}
	in->x0 = d->p[i][j]->xx;
	in->y0 = d->p[i][j]->yy;
	in->c0 = d->p[i][j]->c;
	if (i + 1 < d->c_line)
	{
		in->x1 = d->p[i + 1][j]->xx;
		in->y1 = d->p[i + 1][j]->yy;
		in->c1 = d->p[i + 1][j]->c;
		ft_draw_line(in, d);
	}
}

void	ft_cheak(t_data *data)
{
	char	**array;

	data->c_line = ft_count_line(data);
	array = ft_full_array(data, data->c_line + 1);
	if (array && array[0])
		ft_is_clear(data, array);
	else
	{
		ft_free_arr(array);
		(ft_error("No data in file\n"), free(data), exit(5));
	}
	ft_full_point(data, array);
	ft_free_arr(array);
}

int	ft_close(t_data *data)
{
	ft_error("Window closed.\n");
	if (data->img_intro)
		mlx_destroy_image(data->mlx, data->img_intro);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	ft_free_points(data);
	free(data);
	exit(12);
	return (0);
}

int	ft_dir(int n0, int n1)
{
	if (n0 < n1)
		return (1);
	else
		return (-1);
}
