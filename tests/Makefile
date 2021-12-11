# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:14:52 by cchen             #+#    #+#              #
#    Updated: 2021/12/11 13:07:04 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
GNL = ../src
LIBFT = ../src/libft
GNLFILE = get_next_line.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror test_main.c $(GNL)/$(GNLFILE) -I$(GNL) -I$(LIBFT) -L$(LIBFT) -lft -o $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all
