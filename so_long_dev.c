/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_dev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:06:07 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/21 17:06:07 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printer(t_board **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type != 0)
		{
			ft_printf("%c ", map[i][j].type);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	flood_map(t_board **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type != 0)
		{
			ft_printf("%d ", map[i][j].flood);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
