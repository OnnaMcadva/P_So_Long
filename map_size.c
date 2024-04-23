/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:04 by anmakaro          #+#    #+#             */
/*   Updated: 2024/04/23 13:54:07 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_col(int fd_y)
{
	char	*c;
	int		y;

	while (1)
	{
		c = get_next_line(fd_y);
		if (fd_y < 0)
		{
			ft_putendl_fd(ERROR, 1);
			ft_putendl_fd(ARG_EMPT, 1);
		}
		if (!c)
			break ;
		y = ft_strlen(c) - 1;
		free(c);
	}
	return (y);
}

int	size_row(int fd_x)
{
	char	*c;
	int		x;

	x = 0;
	while (1)
	{
		c = get_next_line(fd_x);
		if (!c)
			break ;
		x++;
		free(c);
	}
	if (x == 0)
	{
		ft_putendl_fd(ERROR, 1);
		ft_putendl_fd(ARG_EMPT, 1);
		exit(0);
	}
	return (x);
}
