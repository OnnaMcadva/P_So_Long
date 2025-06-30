/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:55:54 by anmakaro          #+#    #+#             */
/*   Updated: 2025/06/30 21:28:37 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_graphics(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.space)
		mlx_destroy_image(game->mlx, game->img.space);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.on_exit)
		mlx_destroy_image(game->mlx, game->img.on_exit);
	if (game->img.fin_exit)
		mlx_destroy_image(game->mlx, game->img.fin_exit);
	mlx_destroy_display(game->mlx);
	free_level(game);
	free(game->mlx);
	exit(0);
}

void	clean_pathmap(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_passability[i])
	{
		free(game->map_passability[i]);
		i++;
	}
	free(game->map_passability);
}

void	free_level(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	panic(char *s, t_game *game)
{
	ft_putendl_fd(s, 1);
	if (game->map[0])
		free_level(game);
	exit(0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	clean_graphics(game);
	exit (0);
}
