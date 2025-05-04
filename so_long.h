/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:25:45 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/10 01:25:45 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//-------------------------------INCLUDE-------------------------------
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

//-------------------------------STRUCTS-------------------------------

typedef struct s_player
{
	int		i;
	int		j;
}	t_player;

typedef struct s_board
{
	int		width;
	char	type;
	char	old;
	int		flood;
}	t_board;

typedef struct s_game
{
	int		item_t;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*spr_wall;
	void	*spr_floor;
	void	*spr_player;
	void	*spr_item;
	void	*spr_exit;
}	t_game;

typedef struct s_mmlx
{
	t_board	**map;
	t_game	game;
}	t_mmlx;

//--------------------------------LIBFT--------------------------------
int			ft_printf(const char *s, ...);
void		ft_arg_error(void);
size_t		ft_strlen(const char *str);
void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

//---------------------------------GNL---------------------------------
char		*get_next_line(int fd);

//--------------------------------MAIN---------------------------------
void		exit_mlx(void *mlx, void *win, t_board **map);
int			exit_all(void *param);

//-------------------------------PARSING-------------------------------
t_board		**map_builder(char *map, int height, int width, int fd);
int			map_check(t_board **map, int i, int j);
int			border_check(t_board **map, int height, int width);
int			element_check(t_board **map, int i, int j);
int			collect(t_board **map);
void		null_set(t_board **map);
void		flood_fill(t_board **map);
void		flood(t_board **map, int i, int j);
int			flood_valid(t_board **map, int i, int j);

//--------------------------------ERROR--------------------------------
void		malloc_error(void);
void		parsing_error(void);
t_board		**cleaner(t_board **str);
t_board		**cleaner_fd(t_board **str, int fd);
void		free_fd(char *str, int fd);
void		exit_all_error(void *param);
t_game		exit_mlx_1(t_game game);
void		exit_map(t_board **map);
void		exit_wrong(t_board **map);

//--------------------------------UTILS--------------------------------
int			map_size_w(t_board **map);
int			map_size_h(t_board **map);
char		*hyperdup(char *src);
t_player	player(t_board **map);

//---------------------------------DEV---------------------------------
void		printer(t_board **map);
void		flood_map(t_board **map);

//--------------------------------MOVES--------------------------------
int			move_w(t_board **map);
int			move_a(t_board **map);
int			move_s(t_board **map);
int			move_d(t_board **map);
void		old_p(t_board **map);

//-------------------------------TEXTURE-------------------------------
void		draw_map(t_board **map, t_game game, int i, int j);
t_game		texture(t_board **map, t_game game);
void		destroy_images(t_game game);

//---------------------------------KEY---------------------------------
int			handle_key(int keycode, void *param);
int			w_mech(void *param, int *item);
int			a_mech(void *param, int *item);
int			s_mech(void *param, int *item);
int			d_mech(void *param, int *item);

#endif