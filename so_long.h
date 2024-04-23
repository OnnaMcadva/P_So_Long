/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:27 by anmakaro          #+#    #+#             */
/*   Updated: 2024/04/23 13:54:29 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

# define PLAYER "./textures/player.xpm"
# define COLLECTABLE "./textures/little.xpm"
# define EXIT "./textures/exit.xpm"
# define WALL "./textures/wall.xpm"
# define SPACE "./textures/space.xpm"
# define FIN_EXIT "./textures/fin_exit.xpm"
# define ON_EXIT "./textures/on_exit.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define WIDTH 128
# define HIGHT 128

# define ERROR "\n\033[6;91mError Error Errorg!\033[0m"
# define ARG_BER "\n\033[38;5;214mFile must be of type .ber\033[0m"
# define ARG_LOAD "\n\033[0;92mLoading!..\033[0m\n"
# define ARG_EMPT "\n\033[0;94mThe file is empty or not exist.\033[0m"
# define WON "\n\033[0;96mYou Won! To exit press any bottom on kyeboard\033[0m"

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*space;
	void	*wall;
	void	*exit;
	void	*fin_exit;
	void	*on_exit;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_passability;
	char	temp;
	int		row;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;

void	texturs(t_game *game);
void	check_arg(t_game *game, int argc, char **argv);
void	ft_exit(char *s, t_game *game);
void	all_map_checks(t_game *game, int fd_map);
void	free_map_passability(t_game *game);
void	free_img(t_game *game);
void	free_map(t_game *game);
void	passability_check(t_game *game, int fd_map);
int		size_row(int fd_x);
int		size_col(int fd_y);
int		collectible_on_map(t_game *game);
int		render_img(t_game *game);
int		close_window(t_game *game);
int		move_key(int keycode, t_game *game);
int		close_window(t_game *game);
void	ft_helpa(int n);

#endif
