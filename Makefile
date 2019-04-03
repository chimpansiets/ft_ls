# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/11 09:49:48 by svoort         #+#    #+#                 #
#    Updated: 2019/04/02 15:45:27 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCS = main.c store_flags.c ft_listdir.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I libft/ -I ft_printf/
CFLAGS = -g -Wall -Wextra -Werror -c
MKLIB = make -C libft/ re
MKPRINTF = make -C ft_printf/ re
CC = gcc
LIB = -L ft_printf/ -lftprintf

all: $(NAME)

$(NAME):
	@$(MKLIB)
	@$(MKPRINTF)
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES)
	@$(CC) -o $(NAME) $(OBJS) $(INCLUDES) $(LIB)
	@echo "\033[1;31mMade ft_ls \033[0m"
	@make clean

clean:
	@rm -f $(OBJS)
	@make -C libft/ clean
	@make -C ft_printf/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C ft_printf/ clean

re: fclean all
