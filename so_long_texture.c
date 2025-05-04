/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:51:28 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/29 12:51:28 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	loader(t_game game)
{
	int	i;
	int	j;

	i = 32;
	j = 32;
	game.spr_exit = mlx_xpm_file_to_image(game.mlx, "spr/exit.XPM", &i, &j);
	if (!game.spr_exit)
		return (exit_mlx_1(game));
	game.spr_floor = mlx_xpm_file_to_image(game.mlx, "spr/floor.XPM", &i, &j);
	if (!game.spr_floor)
		return (exit_mlx_1(game));
	game.spr_item = mlx_xpm_file_to_image(game.mlx, "spr/item.XPM", &i, &j);
	if (!game.spr_item)
		return (exit_mlx_1(game));
	game.spr_player = mlx_xpm_file_to_image(game.mlx, "spr/player.XPM", &i, &j);
	if (!game.spr_player)
		return (exit_mlx_1(game));
	game.spr_wall = mlx_xpm_file_to_image(game.mlx, "spr/wall.XPM", &i, &j);
	if (!game.spr_wall)
		return (exit_mlx_1(game));
	return (game);
}

void	draw_map(t_board **map, t_game game, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			if (map[i][j].type == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.spr_wall, j * 32, i * 32);
			else if (map[i][j].type == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.spr_floor, j * 32, i * 32);
			else if (map[i][j].type == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.spr_player, j * 32, i * 32);
			else if (map[i][j].type == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.spr_exit, j * 32, i * 32);
			else if (map[i][j].type == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.spr_item, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

t_game	texture(t_board **map, t_game game)
{
	game.height = map_size_h(map);
	game.width = map_size_w(map);

	game.mlx = mlx_init();
	if (!game.mlx)
		exit_wrong(map);
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32, "so_long");
	if (!game.win)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		exit_wrong(map);
	}
	game = loader(game);
	if (!game.spr_exit)
		exit_wrong(map);
	draw_map(map, game, 0, 0);
	return (game);
}

void	destroy_images(t_game game)
{
	if (game.spr_wall)
		mlx_destroy_image(game.mlx, game.spr_wall);
	if (game.spr_floor)
		mlx_destroy_image(game.mlx, game.spr_floor);
	if (game.spr_item)
		mlx_destroy_image(game.mlx, game.spr_item);
	if (game.spr_player)
		mlx_destroy_image(game.mlx, game.spr_player);
	if (game.spr_exit)
		mlx_destroy_image(game.mlx, game.spr_exit);
}