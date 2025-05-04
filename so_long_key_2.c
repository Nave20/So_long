/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:56:05 by vpirotti          #+#    #+#             */
/*   Updated: 2025/05/04 15:56:05 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	w_mech(void *param, int *item)
{
	t_mmlx		*content;
	int			temp;

	content = (t_mmlx *)param;
	temp = move_w(content->map);
	if (temp == 1)
		(*item)++;
	else if (temp == 28 && *item == content->game.item_t)
	{
		ft_printf("\033[36mVictory, you've gathered : \033[33m%d\033[36m "
			"item(s)\033[0m\n", *item);
		exit_all(content);
	}
	return (temp);
}

int	a_mech(void *param, int *item)
{
	t_mmlx		*content;
	int			temp;

	content = (t_mmlx *)param;
	temp = move_a(content->map);
	if (temp == 1)
		(*item)++;
	else if (temp == 28 && *item == content->game.item_t)
	{
		ft_printf("\033[36mVictory, you've gathered : \033[33m%d\033[36m "
			"item(s)\033[0m\n", *item);
		exit_all(content);
	}
	return (temp);
}

int	s_mech(void *param, int *item)
{
	t_mmlx		*content;
	int			temp;

	content = (t_mmlx *)param;
	temp = move_s(content->map);
	if (temp == 1)
		(*item)++;
	else if (temp == 28 && *item == content->game.item_t)
	{
		ft_printf("\033[36mVictory, you've gathered : \033[33m%d\033[36m "
			"item(s)\033[0m\n", *item);
		exit_all(content);
	}
	return (temp);
}

int	d_mech(void *param, int *item)
{
	t_mmlx		*content;
	int			temp;

	content = (t_mmlx *)param;
	temp = move_d(content->map);
	if (temp == 1)
		(*item)++;
	else if (temp == 28 && *item == content->game.item_t)
	{
		ft_printf("\033[36mVictory, you've gathered : \033[33m%d\033[36m "
			"item(s)\033[0m\n", *item);
		exit_all(content);
	}
	return (temp);
}
