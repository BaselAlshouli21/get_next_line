# -*- Makefile -*-

CC = cc
BUFFER_SIZE ?= 42
FLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(BUFFER_SIZE)
NAME = get_next_line
OBJ_DIR = obj

SRCS = \
	get_next_line.c \
	get_next_line_utils.c \
	main.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c get_next_line.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re