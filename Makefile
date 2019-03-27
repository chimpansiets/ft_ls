# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 18:18:58 by svoort         #+#    #+#                 #
#    Updated: 2019/03/17 12:30:01 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FUN		=	ft_nbrlen.c ft_printf.c ft_prfoper.c ft_atoi.c ft_prfnbr.c \
			ft_itoabase.c ft_strlen.c ft_unicode.c ft_prfdbl.c ft_strcpy.c \
			ft_strdup.c ft_joinfree.c ft_dblhex.c ft_qstr.c helper1.c \
			helper2.c helper3.c helper4.c helper5.c helper6.c helper7.c \
			
FUNDIR	=	./

GFLG	=	gcc -Wall -Wextra -Werror -c

HD		=	$(addprefix -I, .)

OBJDIR	=	./obj/

OBJS	=	$(FUN:.c=.o)

OBJ		=	$(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(NAME): ./libft.h $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(NAME) "ready"

$(OBJDIR)%.o: $(FUNDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(GFLG) $(HD) -o $@ $<

clean:
	@rm -rf $(OBJDIR)
	@echo "Objects deleted"

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) "deleted"

re: fclean all
