/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:53:44 by anmakaro          #+#    #+#             */
/*   Updated: 2025/06/30 21:33:50 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_borders(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[0][y] != '1' || game->map[game->row - 1][y] != '1')
				panic(SURR, game);
			if (game->map[x][0] != '1' || game->map[x][game->col - 1] != '1')
				panic(SURR, game);
			y++;
		}
		x++;
	}
}

void	check_rect(t_game *game)
{
	int	y;
	int	x;
	int	size;

	y = 0;
	x = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[x] != 0)
	{
		y = ft_strlen(game->map[x]);
		if (y != size)
			panic("Error\nMap is not rectangular", game);
		x++;
	}
	validate_borders(game);
}

static void	check_tile(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		game->score++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		panic("Error\nInvalid characters", game);
}

void	validate_elems(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			check_tile(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (game->score == 0)
		panic("Error\nThere is no collectible", game);
	else if (game->exit == 0)
		panic("Error\nThere is no exit", game);
	else if (game->exit > 1)
		panic("Error\nThere must be only one exit", game);
	else if (game->player == 0)
		panic("Error\nThere is no player", game);
	else if (game->player > 1)
		panic("Error\nOnly one player on map ", game);
}

void	validate_map(t_game *game, int fd_map)
{
	ft_putendl_fd(ARG_LOAD, 1);
	validate_elems(game);
	check_rect(game);
	validate_path(game, fd_map);
}