/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:50:09 by adiri             #+#    #+#             */
/*   Updated: 2024/10/31 22:20:19 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (slen);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (slen);
}

static char	*ft_get_one_line(int fd, char *buffer, char *line)
{
	ssize_t	b_read;
	char	*n_line;

	b_read = read(fd, buffer, BUFFER_SIZE);
	if (!b_read)
		return (line);
	while (b_read > 0)
	{
		if (!line)
			line = ft_strdup("");
		*(buffer + b_read) = 0;
		n_line = ft_strjoin(line, buffer);
		free(line);
		line = n_line;
		if (ft_strchr(line, '\n'))
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (b_read == -1)
		return (NULL);
	return (line);
}

static char	*ft_get_the_line(char *o_line)
{
	size_t	i;
	char	*str;

	i = 0;
	while (*(o_line + i) != '\n' && *(o_line + i))
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, o_line, i + 2);
	return (str);
}

static char	*update_line(char *line)
{
	char	*new_line;
	char	*n_pos;

	n_pos = ft_strchr(line, '\n');
	if (n_pos)
		new_line = ft_strdup(n_pos + 1);
	else
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*r_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_get_one_line(fd, buffer, line);
	free(buffer);
	if (!line || !ft_strlen(line))
	{
		free(line);
		return (NULL);
	}
	r_line = ft_get_the_line(line);
	line = update_line(line);
	return (r_line);
}
