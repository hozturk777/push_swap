MAKEFLAGS 			+= --no-print-directory
NAME				= push_swap
LIBFT				= ./lib/libft/libft.a
PRINTF				= ./lib/ft_printf/libftprintf.a
SRC_DIR				= source/
UTL_DIR				= utils/
CMD_DIR				= commands/
ERR_DIR				= error/
VAL_DIR				= validation/
OBJ_DIR				= obj/
CC					= @cc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -rf

PUSH_SWAP_DIR			=	$(SRC_DIR)push_swap.c \
						$(SRC_DIR)sorting_choice.c \
						$(UTL_DIR)get_utils.c \
						$(UTL_DIR)utils.c \
						$(UTL_DIR)sort_utils.c \
						$(UTL_DIR)sortb_utils.c \
						$(UTL_DIR)move_utils.c \
						$(CMD_DIR)swap.c \
						$(CMD_DIR)rotate.c \
						$(CMD_DIR)reverse_rotate.c \
						$(CMD_DIR)push.c \
						$(CMD_DIR)move.c \
						$(ERR_DIR)errors.c \
						$(ERR_DIR)destroy.c \
						$(VAL_DIR)validate.c \
						$(VAL_DIR)validate_number.c \
						

SRCS 				= $(PUSH_SWAP_DIR)

OBJ					= $(PUSH_SWAP_DIR:.c=.o)

COLOR_YELLOW	=	\033[0;33m \033[1m
COLOR_GREEN		=	\033[0;32m \033[1m
COLOR_RED		=	\033[0;31m \033[1m
COLOR_END		=	\033[0m

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) $(PRINTF)
					@$(CC) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
					@echo "\n\e[1m$(COLOR_YELLOW)$(NAME)	$(COLOR_GREEN)[is ready!]\e[0m\n$(COLOR_END)"

$(LIBFT):
					@make -C ./lib/libft
					
$(PRINTF):
					@make -C ./lib/ft_printf

clean:
					@$(RM) -r $(OBJ)
					@make clean -C ./lib/libft
					@make clean -C ./lib/ft_printf
					@echo "\n\e[1m$(COLOR_YELLOW)objects	$(COLOR_RED)[are deleted!]\e[0m$(COLOR_END)"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)
					@echo "\e[1m$(COLOR_YELLOW)$(NAME)	$(COLOR_RED)[is deleted!]\e[0m\n$(COLOR_END)"

re: 				fclean all

.PHONY: 			all clean fclean re