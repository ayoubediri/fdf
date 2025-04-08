/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:50:52 by adiri             #+#    #+#             */
/*   Updated: 2024/12/26 10:54:35 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strdupto(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**array;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	array = ft_calloc(words + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			array[words++] = ft_strdupto(s + i, c);
		while (s[i] != c && s[i])
			i++;
	}
	array[words] = NULL;
	return (array);
}
