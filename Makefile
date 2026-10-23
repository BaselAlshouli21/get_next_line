# -*- Makefile -*-

CC = cc
BUFFER_SIZE ?= 42
BONUS ?= 1
NAME = get_next_line
OBJ_DIR = obj

ifeq ($(BONUS),1)
SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
HEADER = get_next_line_bonus.h
MODE = -D BONUS
else
SRCS = get_next_line.c get_next_line_utils.c main.c
HEADER = get_next_line.h
MODE =
endif

FLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(BUFFER_SIZE) $(MODE)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER) $(OBJ_DIR)/.flags
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re