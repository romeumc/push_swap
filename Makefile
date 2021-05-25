# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:35:42 by rmartins          #+#    #+#              #
#    Updated: 2021/05/25 02:02:15 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcsv
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER = ft_ansi.h

SRC = main.c \
	list_utils.c \
	validate_args.c \
	arg_errors.c \
	sort_instructions.c \
	check_sorted.c \
	sort_algorithm.c


all: $(NAME)

$(NAME): $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "compile executable" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix inc/,$(HEADER))
	@echo $(ANSI_B_BGREEN) "compile push_swap objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -Iinc -c $< -o $@
	@echo $(ANSI_RESET)

clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) fclean -C libft
	rm -f cub3DS
	rm -f $(NAME)
	@echo $(ANSI_RESET) ""

re: fclean all

bonus: all
	
.PHONY: all clean fclean

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"


lib:
	$(MAKE) -C libft

norm:
	@echo $(ANSI_B_RED) "norminette v3" $(ANSI_RESET)
	$(MAKE) norm -C libft
	@norminette $(addprefix inc/,$(HEADER)) $(addprefix src/,$(SRC))

libnorm:
	@echo $(ANSI_B_RED) "libft norminette" $(ANSI_RESET)
	$(MAKE) norm -C libft

run: all
	@echo $(ANSI_B_RED) "Running for debbuger without sanitize" $(ANSI_RESET)
	./$(NAME) $(LIST_INTEGER)

runv: all
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	#valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) $(LIST_INTEGER)
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) $(LIST_INTEGER)

runs: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	gcc $(CFLAGS) -fsanitize=address $(OBJ) $(LIBFT) -o push_swaps
	./push_swaps $(LIST_INTEGER)

LIST_INTEGER = 2 6 20 -2 7 1 5 15 25
LIST_INTEGER = 5 4 3 2
# LIST_INTEGER = 1 2 3 4