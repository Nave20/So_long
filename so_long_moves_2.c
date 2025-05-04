/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:26:06 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/29 11:26:06 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_a2(t_board **map, t_player p)
{
	map[p.i][p.j - 1].type = 'P';
	map[p.i][p.j].type = map[p.i][p.j].old;
	map[p.i][p.j - 1].old = '0';
	return (0);
}

int	move_a(t_board **map)
{
	t_player p;

	p = player(map);
	if (map[p.i][p.j - 1].type == '1')
		return (-1);
	if (map[p.i][p.j - 1].type == 'C')
	{
		map[p.i][p.j - 1].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i][p.j - 1].old = '0';
		return (1);
	}
	if (map[p.i][p.j - 1].type == 'E')
	{
		map[p.i][p.j - 1].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i][p.j - 1].old = 'E';
		return (28);
	}
	if (map[p.i][p.j - 1].type == '0')
		return (move_a2(map, p));
	return (-42);
}

int	move_d2(t_board **map, t_player p)
{
	map[p.i][p.j + 1].type = 'P';
	map[p.i][p.j].type = map[p.i][p.j].old;
	map[p.i][p.j + 1].old = '0';
	return (0);
}

int	move_d(t_board **map)
{
	t_player p;

	p = player(map);
	if (map[p.i][p.j + 1].type == '1')
		return (-1);
	if (map[p.i][p.j + 1].type == 'C')
	{
		map[p.i][p.j + 1].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i][p.j + 1].old = '0';
		return (1);
	}
	if (map[p.i][p.j + 1].type == 'E')
	{
		map[p.i][p.j + 1].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i][p.j + 1].old = 'E';
		return (28);
	}
	if (map[p.i][p.j + 1].type == '0')
		return (move_d2(map, p));
	return (-42);
}
