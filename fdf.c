/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:20:59 by adiri             #+#    #+#             */
/*   Updated: 2025/01/05 10:25:16 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reinitialize_data_pers(t_data *data)
{
	if (data->f != 2)
	{
		data->z = data->c_line;
		data->r_y = 0;
		data->r_x = 4;
		data->r_z = 0.1;
		data->tx = 0;
		data->ty = 0;
		data->dp = 0.5;
		data->f = 2;
	}
}

void	ft_reinitialize_data_iso(t_data *data)
{
	if (data->f != 1)
	{
		data->z = 10;
		data->r_y = 0.2;
		data->r_x = -0.05;
		data->r_z = -0.09;
		data->tx = 0;
		data->ty = 0;
		data->dp = 1;
		data->f = 1;
	}
}

int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac != 2)
	{
		ft_error("Usage : ./fdf <filename>\n");
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_full_data(data, av);
	ft_cheak(data);
	ft_use_windows(data);
	mlx_loop(data->mlx);
	free(data);
}
