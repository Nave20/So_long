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
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

//-------------------------------STRUCTS-------------------------------
typedef struct s_board
{
	char			type;
}	t_board;

//--------------------------------LIBFT--------------------------------
int		ft_printf(const char *s, ...);
void	ft_arg_error(void);
size_t	ft_strlen(const char *str);

//---------------------------------GNL---------------------------------
char	*get_next_line(int fd);

//-------------------------------PARSING-------------------------------
t_board	**map_builder(char *map);

//--------------------------------ERROR--------------------------------
t_board	**cleaner(t_board **str);

//---------------------------------DEV---------------------------------
void	printer(t_board **map);

#endif