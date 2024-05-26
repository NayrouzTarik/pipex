NAME  = pipex

INC = inc/pipex.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = parcing.c \
		ft_split.c \
		utils.c \

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
