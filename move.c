/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:12 by anmakaro          #+#    #+#             */
/*   Updated: 2025/06/30 21:38:03 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, int col, int row, int pressed_key)
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

void	win_game(t_game *game, int col, int row)
{
	game->map[row][col] = 'F';
	render_img(game);
	game->end_game = 1;
	ft_putendl_fd(WON, 1);
}

static void	move_player(t_game *game, int col, int row, int pressed_key)
{
	int	valid;
	int	tcol;
	int	trow;

	tcol = game->player_y;
	trow = game->player_x;
	(void)pressed_key;
	valid = can_move(game, col, row, pressed_key);
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
		print_step(game->move++);
		render_img(game);
	}
	if (valid == 2)
		win_game(game, col, row);
}

void	print_step(int n)
{
	write(1, "Step: ", 6);
	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
}

int	handle_input(int keycode, t_game *game)
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
		close_game(game);
	if (game->end_game != 1)
		move_player(game, col, row, keycode);
	else if (game->end_game == 1)
		close_game(game);
	return (0);
}
