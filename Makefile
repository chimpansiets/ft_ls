# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2017/12/28 19:24:02 by vbrazas        #+#    #+#                 #
#    Updated: 2019/04/15 09:29:18 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls
LIB		=	ft_printf/
LIBFT	=	libft/
LIB_HDR	=	$(LIB)hdr/
SRC_D	=	sources/
SRC		=	$(SRC_D)ft_listdir.c \
			$(SRC_D)main.c \
			$(SRC_D)store_flags.c

OBJ_D	=	obj/
OBJ		=	$(addprefix $(OBJ_D), $(SRC:.c=.o))
LFLAGS	=	-lftprintf -L $(LIB)
IFLAGS	=	-I $(LIB_HDR) -I ./
CFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	make -C $(LIBFT)
	gcc -o $(NAME) $(CFLAGS) $(LFLAGS) $(OBJ)

$(OBJ): | $(OBJ_D)

$(OBJ_D):
	mkdir -p $(OBJ_D)$(SRC_D)

$(OBJ_D)%.o: %.c
	gcc $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_D)
	make fclean -C $(LIBFT)
	make fclean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re
