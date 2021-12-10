# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 11:42:02 by cchen             #+#    #+#              #
#    Updated: 2021/12/10 11:42:28 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower
FUNCTIONS2 = memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap iswhitespace memdelarray strdelarray isupper islower
OBJECTS = $(patsubst %, ft_%.o, $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(patsubst  %, ft_%.c, $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS)) -I.
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

