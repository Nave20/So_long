/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:32:30 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/24 15:32:30 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(t_board **map, int i, int j)
{
	if (map[i][j].type == '1' || map[i][j].flood == 1)
		return ;
	map[i][j].flood = 1;
	flood(map, i - 1, j);
	flood(map, i + 1, j);
	flood(map, i, j - 1);
	flood(map, i, j + 1);
}

int	flood_valid(t_board **map, int i, int j)
{
	int	c;

	c = collect(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type == 'C' && map[i][j].flood == 1)
				c--;
			if (map[i][j].type == 'E' && map[i][j].flood != 1)
				return (0);
			j++;
		}
		i++;
	}
	if (c != 0)
		return (0);
	return (1);
}
