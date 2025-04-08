/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:08:07 by adiri             #+#    #+#             */
/*   Updated: 2025/01/04 21:37:59 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_full_data(t_data *data, char **av)
{
	data->mlx = NULL;
	data->win = NULL;
	data->p = NULL;
	data->img = NULL;
	data->img_intro = NULL;
	data->filename = av[1];
	data->len_line = 0;
	data->c_line = 0;
	data->z = 5;
	data->k = 0;
	data->f = 0;
	data->r_y = 0.2;
	data->r_x = -0.05;
	data->r_z = -0.09;
	data->tx = 0;
	data->ty = 0;
	data->dp = 1;
	data->pp = 0;
}

char	**ft_full_array(t_data *data, int c_line)
{
	char	**array;
	int		i;
	int		fd;
	char	*line;

	array = malloc(c_line * sizeof(char *));
	i = 0;
	if (!array)
		(ft_error("Error on allocation\n"), free(data), exit(2));
	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
	{
		free(array);
		(ft_error("The file may be wrong try again\n"), free(data), exit(3));
	}
	line = get_next_line(fd);
	while (line)
	{
		array[i++] = line;
		line = get_next_line(fd);
	}
	array[i] = NULL;
	close(fd);
	return (array);
}

void	ft_is_clear(t_data *data, char **arr)
{
	int	i;

	i = 0;
	data->len_line = ft_count_par(arr[i++]);
	while (arr[i])
	{
		if (data->len_line != ft_count_par(arr[i++]))
		{
			ft_error("Found wrong line length. Exiting.\n");
			(ft_free_arr(arr), free(data), exit(4));
		}
	}
}

void	ft_full_x(t_data *data, t_p ***x, char **arr, int z)
{
	int		i;
	char	**sp;

	(1) && (i = 0, sp = ft_split(arr[z], ' '));
	(!sp) && (ft_f_this(data, x, z, sp), ft_error("Error\n"), exit(11), i = 0);
	x[z] = ft_calloc((data->len_line + 1), sizeof(t_p *));
	if (!x[z])
	{
		(ft_free_arr(arr), ft_f_this(data, x, i, sp));
		(ft_error("Error on allocation\n"), exit(9));
	}
	while (i < data->len_line)
	{
		x[z][i] = ft_calloc(1, sizeof(t_p));
		if (!x[z][i])
		{
			ft_free_arr(arr);
			(ft_f_this(data, x, z, sp), ft_error("Error\n"), exit(10));
		}
		(1) && (x[z][i]->z = ft_atoi(sp[i]), x[z][i]->yy = 0);
		(1) && (x[z][i]->y = z, x[z][i]->x = i, x[z][i]->xx = 0);
		(1) && (x[z][i]->c = ft_get_color(sp[i]), x[z][i]->zz = 0);
		i++;
	}
	(1) && (ft_free_arr(sp), x[z][i] = NULL);
}

void	ft_full_point(t_data *data, char **arr)
{
	int	i;

	data->p = ft_calloc((data->c_line + 1), sizeof(t_p **));
	if (!data->p)
	{
		ft_error("Error on allocation\n");
		(ft_free_arr(arr), free(data), exit(6));
	}
	i = 0;
	while (i < data->c_line)
		ft_full_x(data, data->p, arr, i++);
	data->p[i] = NULL;
}
