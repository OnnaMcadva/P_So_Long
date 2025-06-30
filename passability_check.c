/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passability_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:20 by anmakaro          #+#    #+#             */
/*   Updated: 2025/06/30 21:27:58 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_path_map(t_game *game, int fd)
{
	int		i;
	char	*c;
	int		x;

	i = 0;
	x = game->row + 1;
	game->map_passability = (char **)malloc(sizeof(char *) * x);
	if (!game->map_passability)
		clean_graphics(game);
	while (i < x)
	{
		c = get_next_line(fd);
		game->map_passability[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}

bool	check_path(t_game *game, int x, int y)
{
	static bool		exit = false;
	static int		ys = 0;

	if (x < 0 || y < 0 || x >= game->row || y >= game->col)
		return (false);
	else if (game->map_passability[x][y] == 'X')
		return (false);
	else if (game->map_passability[x][y] == '1')
		return (false);
	else if (game->map_passability[x][y] == 'E')
		exit = true;
	if (game->map_passability[x][y] == 'C')
		ys++;
	game->map_passability[x][y] = 'X';
	check_path(game, x + 1, y);
	check_path(game, x, y + 1);
	check_path(game, x - 1, y);
	check_path(game, x, y - 1);
	return (ys == game->score && exit);
}

int	is_map_passable(t_game *game)
{
	int		x;
	int		y;
	bool	valid;

	x = game->player_x;
	y = game->player_y;
	valid = check_path(game, x, y);
	return (valid);
}

void	validate_path(t_game *game, int fd_map)
{
	create_path_map(game, fd_map);
	if (!is_map_passable(game))
	{
		clean_pathmap(game);
		close(fd_map);
		panic(PASS, game);
	}
	clean_pathmap(game);
}
