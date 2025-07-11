/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:27 by anmakaro          #+#    #+#             */
/*   Updated: 2025/06/30 21:38:03 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
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

# define ERROR "\n\033[6;91mError Error Error!\033[0m"
# define ARG_BER "\033[38;5;214mPut ./so_long maps/map?.ber\033[0m"
# define ARG_LOAD "\n\033[0;92mLoading!..\033[0m\n"
# define ARG_EMPT "\n\033[0;94mThe file is empty or not exist.\033[0m"
# define WON "\n\033[0;96mYou Won! To exit press any bottom on kyeboard\033[0m"
# define INIT_G "\033[6;91mError\nFailed to initialize game\033[0m"
# define SURR "\033[6;91mError\nThe map is not surrounded by walls\033[0m"
# define PASS "\033[6;91mError\nImpossibale to pass\033[0m"

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

/* so_long.c */
int		map_name(const char *s);
void	start_game(t_game *game);
int		main(int argc, char **argv);

/* free_exit.c */
void	clean_graphics(t_game *game);
void	clean_pathmap(t_game *game);
void	free_level(t_game *game);
void	panic(char *s, t_game *game);
int	close_game(t_game *game);

/* map_checks.c */
void	check_rect(t_game *game);
void	validate_elems(t_game *game);
void	validate_map(t_game *game, int fd_map);

/* map_info.c */
void	textures(t_game *game);
void	put_map(int x, int y, char c, t_game *game);
int		render_img(t_game *game);
int		collectible_on_map(t_game *game);

/* map_size.c */
int		size_col(int fd_y);
int		size_row(int fd_x);
void	write_map(t_game *game, int fd);

/* move.c */
void	win_game(t_game *game, int col, int row);
void	print_step(int n);
int		handle_input(int keycode, t_game *game);

/* passability_check.c */
void	create_path_map(t_game *game, int fd);
bool	check_path(t_game *game, int x, int y);
int		is_map_passable(t_game *game);
void	validate_path(t_game *game, int fd_map);

#endif
