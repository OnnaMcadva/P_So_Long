#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_game {
	char	*mapall;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		players;
	int		gameover;
	int		steps;
	int		score;
	int		max_score;
}				t_game;

# define ERROR "\n\033[6;91mError!\033[0m"

#endif
