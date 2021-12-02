PATH_SRC = ./src/
PATH_UTILS = $(PATH_SRC)utils/
PATH_ERRORS = $(PATH_SRC)errors/
PATH_PARSER = $(PATH_SRC)parser/
PATH_OBJS = ./objs/

NAME = philo

CC = gcc
CFLAGS = -Wextra -Werror -Wall -I ./includes/
RM = rm -rf

SRC =	$(PATH_SRC)philo.c \
		$(PATH_ERRORS)errors.c \
		$(PATH_UTILS)utils.c \
		$(PATH_PARSER)parser.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)errors/
	@mkdir -p $(PATH_OBJS)utils/
	@mkdir -p $(PATH_OBJS)parser/
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean clean

add: fclean
	git add .
	git commit -m "starting"

push: add
	git push
