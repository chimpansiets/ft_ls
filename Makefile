# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/11 09:49:48 by svoort         #+#    #+#                 #
#    Updated: 2019/03/29 17:46:06 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCS = main.c store_flags.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I libft/
CFLAGS = -g -Wall -Wextra -Werror -c
MKLIB = make -C libft/ re
CC = gcc
LIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	@$(MKLIB)
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES)
	@$(CC) -o $(NAME) $(OBJS) $(INCLUDES) $(LIB)
	@echo "\033[1;31mMade ft_ls \033[0m"

clean:
	@rm -f $(OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
