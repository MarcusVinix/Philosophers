PATH_SRC = ./src/
PATH_UTILS = $(PATH_SRC)utils/
PATH_ERRORS = $(PATH_SRC)errors/
PATH_PARSER = $(PATH_SRC)parser/
PATH_DINNER = $(PATH_SRC)dinner/
PATH_OBJS = ./objs/

NAME = philo

CC = gcc
CFLAGS = -Wextra -Werror -Wall -I ./includes/ -pthread -fsanitize=address
RM = rm -rf

SRC =	$(PATH_SRC)philo.c \
		$(PATH_ERRORS)errors.c \
		$(PATH_UTILS)utils.c $(PATH_UTILS)utils_dinner.c $(PATH_UTILS)more_utils.c\
		$(PATH_PARSER)parser.c \
		$(PATH_DINNER)dinner.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)  

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)errors/
	@mkdir -p $(PATH_OBJS)utils/
	@mkdir -p $(PATH_OBJS)parser/
	@mkdir -p $(PATH_OBJS)dinner/
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean clean

add: fclean
	git add .
	git commit -m "melhorando algumas partes"

push: add
	git push

teste:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./philo 3 30 20 30
