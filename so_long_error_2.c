/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:35:07 by vpirotti          #+#    #+#             */
/*   Updated: 2025/05/04 16:35:07 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_all_error(void *param)
{
	t_mmlx		*content;

	content = (t_mmlx *)param;
	destroy_images(content->game);
	exit_mlx(content->game.mlx, content->game.win, content->map);
	printf("\033[31mWhoops, something went wrong\033[0m\n");
	exit(EXIT_FAILURE);
}

t_game	exit_mlx_1(t_game game)
{
	destroy_images(game);
	if (game.win)
		mlx_destroy_window(game.mlx, game.win);
	if (game.mlx)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
	game.spr_exit = NULL;
	return (game);
}

void	exit_map(t_board **map)
{
	cleaner(map);
	printf("\033[31mYour map is too big.\033[0m\n");
	printf("\033[31mPlease fix it !.\033[0m\n");
	exit(EXIT_FAILURE);
}

void	exit_wrong(t_board **map)
{
	cleaner(map);
	printf("\033[31mWhoops, something went wrong\033[0m\n");
	exit(EXIT_FAILURE);
}