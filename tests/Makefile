# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:14:52 by cchen             #+#    #+#              #
#    Updated: 2022/01/01 13:54:35 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ../src
NAME = test
DEBUG = testdbg
GNL = $(SRC)/get_next_line.c
UNITS = test_readfile test_stdout test_error test_multifile
TESTS = $(patsubst %, ./src/units/%.c, $(UNITS))
LIBDIR = $(SRC)/libft
LIBFT = $(LIBDIR)/libft.a
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower
FUNCTIONS2 = memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap iswhitespace imin
FUNCTIONS_VECTOR = vecnew vecfree vecfrom veccopy vecresize
FUNCTIONS = $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS) $(FUNCTIONS_VECTOR)
OBJECTS = $(patsubst %, $(LIBDIR)/ft_%.o, $(FUNCTIONS))

all: $(NAME)

alldbg: $(DEBUG)

$(NAME):
	gcc -Wall -Wextra -Werror -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits ./src/test_main.c $(TESTS) $(GNL) -I./includes -I$(LIBDIR) -L$(LIBDIR) -lft -o $(NAME)

$(DEBUG):
	gcc -Wall -Wextra -Werror -g ./src/test_main.c $(TESTS) $(GNL) -I./includes -I$(LIBDIR) -L$(LIBDIR) -lft -o $(DEBUG)

$(LIBDIR)/%.o: $(lIBDIR)/%.c
	gcc -Wall -Wextra -Werror -c $(CFLAGS) -I$(LIBDIR) $< -o $@

$(LIBFT): $(OBJECTS)
	ar -rcs $(LIBFT) $^
	ranlib $(LIBFT)

fclean:
	@rm -f $(NAME) $(DEBUG)

re: fclean all

redbg: fclean alldbg
