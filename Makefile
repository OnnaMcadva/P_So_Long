# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annavm <annavm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:18:47 by anmakaro          #+#    #+#              #
#    Updated: 2025/06/29 18:27:14 by annavm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED		= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
ORANGE		= \033[38;5;220m
GREEN_BR	= \033[38;5;118m

LIBFT_DIR    = libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_PATH = ./minilibx-linux
MLXFLAGS      = -L$(MINILIBX_PATH) -lmlx -I$(MINILIBX_PATH) -lXext -lX11

NAME          = so_long
CC            = cc
FLAGS         = -Wall -Werror -Wextra -g
SRC           = so_long.c map_checks.c map_info.c map_size.c move.c passability_check.c free_exit.c
OBJ           = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(MAGENTA)Getting libft ready$(DEF_COLOR)"
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(GREEN_BR)$(NAME) is ready!$(DEF_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) $(LIBFT)  -s
	

clean:
	@echo "$(YELLOW)Removing libft$(DEF_COLOR)"
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(DEF_COLOR)"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all
	@echo "$(BLUE)Cleaned and rebuilt everything for $(NAME).$(DEF_COLOR)"

.PHONY: all clean fclean re
