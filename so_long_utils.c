/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:21:00 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/24 12:21:00 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_w(t_board **map)
{
	int	j;

	j = 0;
	while (map[0][j].type != 0)
		j++;
	return (j);
}

int	map_size_h(t_board **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

char	*hyperdup(char *src)
{
	char	*res;
	size_t	index;

	index = 0;
	res = (char *) malloc ((ft_strlen(src) + 2) * sizeof (char));
	if (res == NULL)
		return (NULL);
	while (src[index])
	{
		res[index] = src[index];
		index++;
	}
	res[index] = '\n';
	res[index + 1] = '\0';
	free(src);
	return (res);
}

t_player	player(t_board **map)
{
	t_player	player;
	int			j;
	int			i;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type == 'P')
			{
				player.i = i;
				player.j = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	player.i = -1;
	player.j = -1;
	return (player);
}
