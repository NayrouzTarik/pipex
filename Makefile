# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:37:25 by ntarik            #+#    #+#              #
#    Updated: 2024/06/09 21:55:20 by ntarik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = pipex

INC = inc/pipex.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = ft_split.c \
		helper.c \
		parse.c \
		init_pipex.c \
		helper2.c \
		main.c \
		ft_error.c \
		spc_case.c \
		check_args.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
