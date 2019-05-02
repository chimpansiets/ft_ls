# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/28 13:01:37 by svoort         #+#    #+#                 #
#    Updated: 2019/05/02 17:59:45 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -g -Wall -Wextra -Werror
MKEX = gcc $(FLAGS) -o
_SRC = main.c check_bonus.c
SRC = $(addprefix ./srcs/, $(_SRC))
OBJECT = $(_SRC:.c=.o)
COMP = gcc -g -c
FT_LS = ft_ls

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

$(FT_LS) : $(OBJECT)
	@printf "$(RED)FT_LS building...\r$(END_C)"
	@sleep 1
	@$(MKEX) $(FT_LS) $(OBJECT) -L libft/ -lft
	@printf "\r" && printf $(CLEAR) && printf "$(GREEN)FT_LS built!\n$(END_C)"

$(OBJECT) :
	@make -C libft/
	@$(COMP) $(SRC) $(FLAGS) -I libft/

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
