/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:58:59 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/24 12:58:59 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	e_check_two(int e, int p, int c)
{
	if (e != 1)
		return (0);
	if (p != 1)
		return (0);
	if (c < 1)
		return (0);
	return (1);
}

int	element_check(t_board **map, int i, int j)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type == 'E')
				e++;
			if (map[i][j].type == 'P')
				p++;
			if (map[i][j].type == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (e_check_two(e, p, c));
}

int	collect(t_board **map)
{
	int	j;
	int	i;
	int	c;

	c = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	null_set(t_board **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			map[i][j].flood = 0;
			j++;
		}
		i++;
	}
}

void	flood_fill(t_board **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type == 'P')
				flood(map, i, j);
			j++;
		}
		i++;
	}
}
