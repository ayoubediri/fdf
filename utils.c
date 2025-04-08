/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:47:00 by adiri             #+#    #+#             */
/*   Updated: 2025/01/04 13:27:20 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_count(char *str, int c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

int	ft_count_line(t_data *data)
{
	ssize_t	b_read;
	int		fd;
	int		c;
	char	buffer[BUFFER + 1];

	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		(ft_error("The file may be wrong try again\n"), free(data), exit(1));
	b_read = read(fd, buffer, BUFFER);
	c = 0;
	while (b_read)
	{
		buffer[b_read] = 0;
		c += ft_count(buffer, '\n');
		b_read = read(fd, buffer, BUFFER);
	}
	close(fd);
	return (c);
}

int	ft_is_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	return (0);
}

int	ft_get_index(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}
