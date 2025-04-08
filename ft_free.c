/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:32 by adiri             #+#    #+#             */
/*   Updated: 2025/01/04 22:36:47 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_f_this(t_data *data, t_p ***p, int n, char **sp)
{
	int	i;
	int	j;

	i = 0;
	while (i <= n)
	{
		j = 0;
		while (p && p[i] && p[i][j])
			free(p[i][j++]);
		free(p[i++]);
	}
	free(p);
	i = 0;
	while (sp && sp[i])
		free(sp[i++]);
	free(sp);
	free(data);
}

void	ft_free_points(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data || !data->p)
		return ;
	while (i < data->c_line)
	{
		j = 0;
		while (j < data->len_line)
		{
			if (data->p[i][j])
				free(data->p[i][j]);
			j++;
		}
		if (data->p[i])
			free(data->p[i]);
		i++;
	}
	free(data->p);
	data->p = NULL;
}
