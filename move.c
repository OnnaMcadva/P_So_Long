/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:12 by anmakaro          #+#    #+#             */
/*   Updated: 2024/04/23 13:54:15 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_game *game, int col, int row, int pressed_key)
{
	game->temp = '0';
	if (game->map[row][col] == '1')
		return (-1);
	if (game->map[row][col] == 'C')
		game->score--;
	if (game->map[row][col] == 'E' && game->score > 0)
	{
		game->temp = 'O';
		return (1);
	}
	if (game->map[row][col] == 'E' && game->score == 0)
	{
		return (2);
	}
	if (pressed_key != W && pressed_key != S && pressed_key != A
		&& pressed_key != D)
		return (-1);
	else
		return (1);
}

void	end_game(t_game *game, int col, int row)
{
	game->map[row][col] = 'F';
	render_img(game);
	game->end_game = 1;
	ft_putendl_fd(WON, 1);
}

static void	moving(t_game *game, int col, int row, int pressed_key)
{
	int	valid;
	int	tcol;
	int	trow;

	tcol = game->player_y;
	trow = game->player_x;
	(void)pressed_key;
	valid = valid_move(game, col, row, pressed_key);
	if (valid != -1)
	{
		game->player_y = col;
		game->player_x = row;
		if (game->temp != 'O')
			game->map[row][col] = 'P';
		else
			game->map[row][col] = 'O';
		if (game->map[trow][tcol] != 'O')
			game->map[trow][tcol] = '0';
		else
			game->map[trow][tcol] = 'E';
		ft_helpa(game->move++);
		render_img(game);
	}
	if (valid == 2)
		end_game(game, col, row);
}

void	ft_helpa(int n)
{
	write(1, "Step: ", 6);
	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
}

int	move_key(int keycode, t_game *game)
{
	int	col;
	int	row;

	col = game->player_y;
	row = game->player_x;
	if (keycode == A)
		col--;
	else if (keycode == W)
		row--;
	else if (keycode == S)
		row++;
	else if (keycode == D)
		col++;
	else if (keycode == ESC)
		close_window(game);
	if (game->end_game != 1)
		moving(game, col, row, keycode);
	else if (game->end_game == 1)
		close_window(game);
	return (0);
}
