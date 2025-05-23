/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:00:31 by vpirotti          #+#    #+#             */
/*   Updated: 2024/11/29 14:00:31 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	if (src == NULL || size == 0)
		return (ft_strlenn(src));
	index = 0;
	while (index < size - 1 && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlenn(src));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	len = ft_strlenn(s2);
	j = ft_strlenn(s1) + 1;
	i = 0;
	res = (char *) malloc ((j + len) * sizeof(char));
	if (!res)
		return (free (s1), NULL);
	ft_strlcpy(res, s1, j);
	while (i < len)
	{
		res[j - 1] = s2[i];
		i++;
		j++;
	}
	res[j - 1] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	index;

	index = 0;
	res = (char *) malloc ((ft_strlenn(src) + 1) * sizeof (char));
	if (res == NULL)
		return (NULL);
	while (src[index])
	{
		res[index] = src[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

void	*ft_memset(void *mem, int c, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) mem;
	while (i < size)
	{
		str[i] = (char) c;
		i++;
	}
	return (mem);
}
