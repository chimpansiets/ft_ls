/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:31 by svoort         #+#    #+#                */
/*   Updated: 2019/08/21 16:20:37 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <dirent.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

# define FLAG_L	g_fl.flags.l
# define FLAG_BIG_R g_fl.flags.biggie_r
# define FLAG_A	g_fl.flags.a
# define FLAG_R	g_fl.flags.r
# define FLAG_T	g_fl.flags.t

typedef struct			s_flags {
	char				l;
	char				biggie_r;
	char				a;
	char				r;
	char				t;
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

t_fl					g_fl;

/*
**	check_bonus.c
*/

int						ft_check_bonus_flags(int argc, char **argv);

/*
**	ft_error.c
*/

void					ft_error(char *str);

/*
**	solve_sudoku.c
*/

void					solve_sudoku(int argc, char **argv);

/*
**	read_sudoku_input.c
*/

char					**read_sudoku_file(int argc, char **argv);

/*
**	schone.c
*/

void					schone(void);

/*
**	check_flags.c
*/

void					ft_check_real_flags(int argc, char **argv);

/*
**	print_files.c
*/

void					print_files(char *folder);

/*
**	get_folders.c
*/

void					print_folders(char **folders);
char					**get_folders(int argc, char **argv);

/*
**	get_path.c
*/

char					*get_path(char *folder, char *dir_name);

/*
**	print_file.c
*/

void					ft_printfile(char *folder, struct dirent *dir);

#endif
