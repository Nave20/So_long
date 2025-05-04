/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:29:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/10 01:29:29 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <errno.h>

t_game	mlx_null(t_board **map)
{
	t_game	game;

	game.item_t = collect(map);
	game.height = 0;
	game.width = 0;
	game.mlx = NULL;
	game.win = NULL;
	game.spr_exit = NULL;
	game.spr_floor = NULL;
	game.spr_player = NULL;
	game.spr_wall = NULL;
	game.spr_item = NULL;
	return (game);
}

void	exit_mlx(void *mlx, void *win, t_board **map)
{
	if (win)
		mlx_destroy_window(mlx, win);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	cleaner(map);
}

int	exit_all(void *param)
{
	t_mmlx		*content;

	content = (t_mmlx *)param;
	destroy_images(content->game);
	exit_mlx(content->game.mlx, content->game.win, content->map);
	exit(EXIT_SUCCESS);
}

t_board	**enter(char *str)
{
	t_board	**map;

	if (ft_strncmp(&str[ft_strlen(str) - 4], ".ber", 4) != 0)
		return (NULL);
	map = map_builder(str, 0, 0, 0);
	if (!map)
		return (malloc_error(), NULL);
	if (map_check(map, 0, 0) != 1)
		return (cleaner(map), NULL);
	if (border_check(map, map_size_h(map), map_size_w(map)) != 1)
		return (cleaner(map), NULL);
	if (element_check(map, 0, 0) != 1)
		return (cleaner(map), NULL);
	null_set(map);
	flood_fill(map);
	if (flood_valid(map, 0, 0) != 1)
		return (cleaner(map), NULL);
	old_p(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_board	**map;
	t_game	game;
	t_mmlx	content;
	if (argc != 2)
	{
		ft_arg_error();
		return (0);
	}
	map = enter(argv[1]);
	if (!map)
		parsing_error();
	if (map_size_w(map) > 60 || map_size_h(map) > 33)
		exit_map(map);
	game = mlx_null(map);
	content.map = map;
	content.game = texture(map, game);
	if (!content.game.mlx)
		exit_wrong(map);
	mlx_key_hook(content.game.win, handle_key, &content);
	mlx_hook(content.game.win, 17, 0, exit_all, &content);
	mlx_loop(content.game.mlx);
	return (0);
}
