# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 21:48:24 by msales-a          #+#    #+#              #
#    Updated: 2020/05/24 11:52:26 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERS = libftprintf.h

SOURCES = ft_printf.c \
	    libflow.c \
	    libformat.c \
		libparser.c \
		libprint.c \
		libtemp.c \
		libtest.c \
		libutil.c \
		libfunc.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@gcc -Wall -Wextra -Werror -c -g $(SOURCES)
	@ar rcs $(NAME) $(OBJECTS)

clean :
	@rm -f $(OBJECTS)

fclean :
	@rm -f $(NAME)

re : all clean

teste: $(NAME) local_teste.c
	@gcc -Wall -Wextra -Werror -fsanitize=address -c -g local_teste.c
	@gcc local_teste.o $(NAME)
	@./a.out

testefree: $(NAME) local_teste.c
	@gcc -c -g local_teste.c
	@gcc local_teste.o $(NAME)
	@./a.out
