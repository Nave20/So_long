/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:46:56 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/10 01:46:56 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	border_check(t_board **map, int	height, int width)
// {
// 	int	i;
//
// 	i = 0;
// 	while ()
// }

t_board	**cleaner(t_board **str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}