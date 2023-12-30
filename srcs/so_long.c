#include "../incs/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_init_values(&game);
	if (argc == 2)
	{
		start_game(argv[1], &game);
	}
	ft_putendl_fd(ERROR, 1);
	return (0);
}
