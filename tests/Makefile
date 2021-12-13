# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:14:52 by cchen             #+#    #+#              #
#    Updated: 2021/12/13 15:18:15 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ../src
NAME = test
GNL = $(SRC)/get_next_line.c
LIBDIR = $(SRC)/libft
LIBFT = $(LIBDIR)/libft.a
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower
FUNCTIONS2 = memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap
OBJECTS = $(patsubst %, $(LIBDIR)/ft_%.o, $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS))

all: $(LIBFT) $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror test_main.c $(GNL) -I./includes -I$(LIBDIR) -L$(LIBDIR) -lft -o $(NAME)

$(LIBDIR)/%.o: $(lIBDIR)/%.c
	gcc -Wall -Wextra -Werror -c $(CFLAGS) -I$(LIBDIR) $< -o $@

$(LIBFT): $(OBJECTS)
	ar -rcs $(LIBFT) $^
	ranlib $(LIBFT)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(LIBFT) $(NAME)

re: fclean all
