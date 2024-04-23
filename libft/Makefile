# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:18:47 by anmakaro          #+#    #+#              #
#    Updated: 2024/04/23 13:48:18 by anmakaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

SRC = ft_strncmp.c \
	ft_strchr.c \
	ft_putendl_fd.c  \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strtrim.c \
	ft_putnbr_fd.c \
	get_next_line.c \
	get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
