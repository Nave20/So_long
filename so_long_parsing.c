/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:35:34 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/10 01:35:34 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_board	**map_filler(t_board **array, char *map, int height)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (cleaner(array));
	while (i < height)
	{
		line = get_next_line(fd);
		if (!line)
			return (cleaner(array));
		j = 0;
		while (j < ft_strlen(line))
		{
			array[i][j] .type = line[j];
			j++;
		}
		i++;
		free(line);
	}
	return (array);
}

t_board	**array_alloc(int width, int height, char *map)
{
	t_board	**array;
	int		i;

	i = 0;
	array = malloc((height + 1) * sizeof(t_board*));
	if (!array)
		return (NULL);
	while (i < height)
	{
		array[i] = malloc((width) * sizeof(t_board));
		if (!array[i])
			return (cleaner(array));
		i++;
	}
	array[i] = NULL;
	return (map_filler(array, map, height));
}

t_board	**map_builder(char *map)
{
	int		fd;
	int		width;
	int		height;
	char	*line;

	height = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	width = (int) ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != width)
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
		if (!line && errno == -8)
			return (NULL);
		height++;
	}
	close(fd);
	return (array_alloc(width, height, map));
}
