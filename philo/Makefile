NAME     = philo

# Mandatory 
SRC_DIR  = ./src
OBJ_DIR  = ./obj
SRCS     = utils.c even_odd.c init.c exec.c main.c pthread.c print.c \
			error_check.c current_t.c death_checker.c free.c
OBJS     = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CC 		 = gcc -fsanitize=thread
CCD		 = gcc -g -Og -std=gnu99 
CFLAGS	 = -Wall -Wextra -Werror

RM       = rm -rf

INCLUDES = -Iincludes
LIB      = -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(INCLUDES) -c $< -o $@

test:
	@make && ./philo

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all ./philo

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re