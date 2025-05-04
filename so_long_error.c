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

void	malloc_error(void)
{
	ft_putendl_fd("\033[31mAn allocation of fd error occured.\033[0m", 2);
	exit(EXIT_FAILURE);
}

void	parsing_error(void)
{
	ft_putendl_fd("\033[31mThe provided map isn't valid.\033[0m", 2);
	ft_putendl_fd("\033[31mPlease fix it !\033[0m", 2);
	exit(EXIT_FAILURE);
}

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

t_board	**cleaner_fd(t_board **str, int fd)
{
	int	i;

	close(fd);
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

void	free_fd(char *str, int fd)
{
	free(str);
	close(fd);
	parsing_error();
}
