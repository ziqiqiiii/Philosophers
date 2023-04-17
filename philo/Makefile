NAME     = philo

# Mandatory 
SRC_DIR  = ./src
OBJ_DIR  = ./obj
SRCS     = utils.c even_odd.c init.c exec.c main.c pthread.c print.c
OBJS     = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CC 		 = gcc
CCD		 = gcc -g -Og -std=gnu99
CFLAGS	 = -Wall -Wextra -Werror

RM       = rm -rf

INCLUDES = -Iincludes
LIB      = -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CCD) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	@$(CCD) $(INCLUDES) -c $< -o $@

test:
	@make && ./philo

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re