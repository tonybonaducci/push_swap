NAME	=push_swap

LIBFT	=./libft/libft.a
INC		= inc/
SRC_DIR = srcs/
OBJ_DIR = obj/

CC	= gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f

COMMANDS_DIR	=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_algos.c \
						$(SRC_DIR)commands/swap.c \
						$(SRC_DIR)commands/trouble_shuffle.c

STACK_TOOLS_DIR	=	$(SRC_DIR)stack_tools/a_stack_manager.c \
						$(SRC_DIR)stack_tools/b_stack_manager.c \
						$(SRC_DIR)stack_tools/stack_utils.c

PUSH_SWAP_DIR = 			$(SRC_DIR)push_swap/main.c

SRCS			= $(COMMANDS_DIR) $(STACK_TOOLS_DIR) $(PUSH_SWAP_DIR)

OBJ				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
				@make all

$(LIBFT):
				@make -C ./libft

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@	

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re:				fclean all

.PHONY:			start all clean fclean re