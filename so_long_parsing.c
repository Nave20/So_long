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
		if (!line && errno == -8)
			return (cleaner_fd(array, fd));
		j = 0;
		while (line[j] && line[j] != '\n')
		{
			array[i][j].type = line[j];
			j++;
		}
		i++;
		free(line);
	}
	close(fd);
	return (array);
}

t_board	**array_alloc(int width, int height, char *map)
{
	t_board	**array;
	int		i;

	i = 0;
	array = malloc((height + 1) * sizeof(t_board));
	if (!array)
		return (NULL);
	while (i < height)
	{
		array[i] = malloc((width) * sizeof(t_board));
		if (!array[i])
			return (cleaner(array));
		array[i][width - 1].type = 0;
		i++;
	}
	array[i] = NULL;
	return (map_filler(array, map, height));
}

t_board	**map_builder(char *map, int height, int width, int fd)
{
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), NULL);
	width = (int) ft_strlen(line);
	while (line)
	{
		if (line[ft_strlen(line) - 1] != '\n')
			line = hyperdup(line);
		if ((int) ft_strlen(line) != width)
			return (free_fd(line, fd), NULL);
		free(line);
		line = get_next_line(fd);
		if (!line && errno == -8)
			return (close(fd), NULL);
		height++;
	}
	close(fd);
	return (array_alloc(width, height, map));
}

int	map_check(t_board **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type != '1' && map[i][j].type != 'P'
				&& map[i][j].type != '0' && map[i][j].type != 'C'
				&& map[i][j].type != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	border_check(t_board **map, int height, int width)
{
	int	i;

	i = 0;
	while (map[0][i].type != 0)
	{
		if (map[0][i].type != '1')
			return (0);
		if (map[height - 1][i].type != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0].type != '1')
			return (0);
		if (map[i][width - 1].type != '1')
			return (0);
		i++;
	}
	return (1);
}
