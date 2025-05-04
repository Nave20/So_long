/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:41:30 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/25 11:41:30 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	old_p(t_board **map)
{
	t_player p;

	p = player(map);
	map[p.i][p.j].old = '0';
}

int	move_w2(t_board **map, t_player p)
{
	map[p.i - 1][p.j].type = 'P';
	map[p.i][p.j].type = map[p.i][p.j].old;
	map[p.i - 1][p.j].old = '0';
	return (0);
}

int	move_w(t_board **map)
{
	t_player p;

	p = player(map);
	if (map[p.i - 1][p.j].type == '1')
		return (-1);
	if (map[p.i - 1][p.j].type == 'C')
	{
		map[p.i - 1][p.j].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i - 1][p.j].old = '0';
		return (1);
	}
	if (map[p.i - 1][p.j].type == 'E')
	{
		map[p.i - 1][p.j].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i - 1][p.j].old = 'E';
		return (28);
	}
	if (map[p.i - 1][p.j].type == '0')
		return (move_w2(map, p));
	return (-42);
}

int	move_s2(t_board **map, t_player p)
{
	map[p.i + 1][p.j].type = 'P';
	map[p.i][p.j].type = map[p.i][p.j].old;
	map[p.i + 1][p.j].old = '0';
	return (0);
}

int	move_s(t_board **map)
{
	t_player p;

	p = player(map);
	if (map[p.i + 1][p.j].type == '1')
		return (-1);
	if (map[p.i + 1][p.j].type == 'C')
	{
		map[p.i + 1][p.j].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i + 1][p.j].old = '0';
		return (1);
	}
	if (map[p.i + 1][p.j].type == 'E')
	{
		map[p.i + 1][p.j].type = 'P';
		map[p.i][p.j].type = map[p.i][p.j].old;
		map[p.i + 1][p.j].old = 'E';
		return (28);
	}
	if (map[p.i + 1][p.j].type == '0')
		return (move_s2(map, p));
	return (-42);
}