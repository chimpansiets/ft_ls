# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/28 13:01:37 by svoort         #+#    #+#                 #
#    Updated: 2019/08/29 09:06:50 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -g -Wall -Wextra -Werror -I includes/
MKEX = gcc $(FLAGS) -o
_BONUS = check_bonus.c solve_sudoku.c read_sudoku_input.c solve_shop.c
_USEFUL = main.c ft_error.c check_flags.c print_files.c get_folders.c \
		get_path.c print_file.c print_blocks.c free.c linelist.c \
		sort_list.c
BONUS = $(addprefix bonus/, $(_BONUS))
USEFUL = $(addprefix useful/, $(_USEFUL))
_SRC = $(BONUS) $(USEFUL)
SRC = $(addprefix ./srcs/, $(_SRC))
OBJECT = $(SRC:.c=.o)
COMP = gcc -c
FT_LS = ft_ls
OBJDIR = ./obj

# Colors
RED				= \033[31;1m
GREEN		    = \033[32;1m
YELLOW			= \033[33;1m
BLUE			= \033[34;1m
PURPLE			= \033[35;1m
CYAN			= \033[36;1m
LGREY			= \033[37;1m
END_C			= \033[m
CLEAR			= "\033[K"

all : $(FT_LS)

%.o : %.c
	@$(COMP) $(FLAGS) $< -o $@

$(FT_LS) : $(OBJECT)
	@make -C libft/
	@printf "$(RED)FT_LS building...\r$(END_C)"
	@sleep 1
	@$(MKEX) $(FT_LS) $(OBJECT) -L libft/ -lft
	@printf "\r" && printf $(CLEAR) && printf "$(GREEN)FT_LS built!\n$(END_C)"

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJECT)

fclean : clean
	@make fclean -C libft/
	@rm -f $(FT_LS)

re : fclean all

.PHONY: all clean fclean re
.SILENT:
print-%  : ; @echo $* = $($*)
