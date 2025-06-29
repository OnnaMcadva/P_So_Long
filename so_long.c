/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:53:18 by anmakaro          #+#    #+#             */
/*   Updated: 2025/06/29 20:16:06 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(const char *s)
{
	const char	*prefix;
	const char	*suffix;
	size_t		s_len;
	size_t		prefix_len;
	size_t		suffix_len;

	prefix = "maps/";
	suffix = ".ber";
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	prefix_len = ft_strlen(prefix);
	suffix_len = ft_strlen(suffix);
	if (s_len < prefix_len + suffix_len)
		return (0);
	if (ft_strncmp(s, prefix, prefix_len) != 0)
		return (0);
	if (ft_strcmp(s + s_len - suffix_len, suffix) != 0)
		return (0);
	return (1);
}

static	void	map_init(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
	game->end_game = 0;
	game->move = 1;
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * WIDTH,
			game->row * HIGHT, "So_long");
	textures(game);
	render_img(game);
	mlx_key_hook(game->win, move_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_expose_hook(game->win, render_img, game);
	mlx_loop(game->mlx);
}

static int	init_game(t_game *game, const char *filename)
{
	int	fd_x;
	int	fd_y;
	int	fd_map;
	int	fd;

	fd_x = open(filename, O_RDONLY);
	fd_y = open(filename, O_RDONLY);
	fd_map = open(filename, O_RDONLY);
	if (fd_x < 0 || fd_y < 0 || fd_map < 0)
		return (0);
	game->score = collectible_on_map(game);
	game->row = size_row(fd_x);
	game->col = size_col(fd_y);
	fd = open(filename, O_RDONLY);
	write_map(game, fd);
	all_map_checks(game, fd_map);
	close(fd_x);
	close(fd_y);
	close(fd);
	close(fd_map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !map_name(argv[1]))
	{
		ft_putendl_fd(ERROR, 1);
		ft_putendl_fd(ARG_BER, 1);
		exit(0);
	}
	map_init(&game);
	if (!init_game(&game, argv[1]))
	{
		ft_putendl_fd("Error\nFailed to initialize game", 1);
		exit(1);
	}
	start_game(&game);
	return (0);
}
