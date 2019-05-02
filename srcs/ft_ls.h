/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:31 by svoort         #+#    #+#                */
/*   Updated: 2019/05/01 15:28:38 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line.h"

typedef struct			s_flags {
	char				a;
	char				l;
	char				r;
	char				R;
	char				t;
	char				sudoku;
	char				katsu;
	char				shop;
	char				rng;
	char				dedicate;
	char				mimma;
	char				coalitions;
	char				vela;
}						t_flags;

typedef struct			s_fl {
	t_flags				flags;
	char				**files;
}						t_fl;

typedef struct			s_dir {
	char				*title;
	int					dm;
	DIR					*dir;
	char				**names;
	u_quad_t			blocks_num;
}						t_dir;

t_fl					*g_fl;

#endif
