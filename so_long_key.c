/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:54:21 by vpirotti          #+#    #+#             */
/*   Updated: 2025/05/01 17:54:21 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mechanics(int keycode, void *param, int *step)
{
	t_mmlx		*content;
	static int	item = 0;

	content = (t_mmlx *)param;
	if (keycode == 'w')
	{
		if (w_mech(content, &item, step) != -1)
			ft_printf(RESET"step -> \033[33m%d\033[0m\n", (*step)++);
	}
	else if (keycode == 's')
	{
		if (s_mech(content, &item, step) != -1)
			ft_printf(RESET"step -> \033[33m%d\033[0m\n", (*step)++);
	}
	else if (keycode == 'a')
	{
		if (a_mech(content, &item, step) != -1)
			ft_printf(RESET"step -> \033[33m%d\033[0m\n", (*step)++);
	}
	else if (keycode == 'd')
	{
		if (d_mech(content, &item, step) != -1)
			ft_printf(RESET"step -> \033[33m%d\033[0m\n", (*step)++);
	}
}

int	handle_key(int keycode, void *param)
{
	t_mmlx		*content;
	static int	step = 1;

	content = (t_mmlx *)param;
	if (keycode == 65307)
	{
		ft_printf("\033[34mGame closed.\033[0m\n");
		exit_all(content);
	}
	if (keycode == 'w' || keycode == 's' || keycode == 'a' || keycode == 'd')
	{
		mechanics(keycode, content, &step);
	}
	mlx_clear_window(content->game.mlx, content->game.win);
	draw_map(content->map, content->game, 0, 0);
	return (0);
}
