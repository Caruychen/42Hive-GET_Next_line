# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 12:47:55 by cchen             #+#    #+#              #
#    Updated: 2022/01/01 13:50:08 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower
FUNCTIONS2 = memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap iswhitespace memdelarray strdelarray isupper islower imin imax
FUNCTIONS_VECTOR = vec_new vec_free vec_from vec_copy vec_resize
FUNCTIONS = $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS) 
OBJECTS = $(patsubst %, ft_%.o, $(FUNCTIONS)) $(patsubst %, %.o, $(FUNCTIONS_VECTOR))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(patsubst  %, ft_%.c, $(FUNCTIONS)) $(patsubst %, %.c, $(FUNCTIONS_VECTOR)) -I.
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
