/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:04:56 by adiri             #+#    #+#             */
/*   Updated: 2025/01/04 17:15:50 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_par(char *str)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] && str[i] != '\n')
			c++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (c);
}

int	ft_get_hex(char *s)
{
	int	i;
	int	n;
	int	hex;

	i = 0;
	n = 0;
	hex = 0;
	if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x'))
	{
		i += 2;
		while (ft_is_hex(s[i + n]))
			n++;
		if (n >= 6)
			n -= 6;
		else
			n = 0;
		while (ft_is_hex(s[i + n]))
		{
			hex = 16 * hex + ft_get_index(s[i + n]);
			n++;
		}
		return (hex);
	}
	return (0);
}

int	ft_get_color(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str && str[i] == ',')
		return (ft_get_hex(str + i + 1));
	return (0xffffff);
}

void	ft_get_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_error("Error in mlx : ft_get_mlx()\n");
		ft_free_points(data);
		free(data);
		exit(12);
	}
}

void	ft_get_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	if (!data->win)
	{
		ft_error("Error in win : ft_get_win()\n");
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_free_points(data);
		free(data);
		exit(13);
	}
}
