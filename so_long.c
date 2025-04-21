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

int	main(int argc, char **argv)
{
	t_board	**test;
	int		height;
	int		width;

	if (argc != 2)
	{
		ft_arg_error();
		return (0);
	}
	test = map_builder(argv[1]);
	if (test)
	{
		printer(test);
		cleaner(test);
	}
	else
		ft_printf("test2");
	return (0);
}
