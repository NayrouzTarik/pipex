# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:37:25 by ntarik            #+#    #+#              #
#    Updated: 2024/05/27 18:32:50 by ntarik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = pipex

INC = inc/pipex.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_split.c \
		utils.c \
		parse.c \
		init_pipex.c \

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
