/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:31 by svoort         #+#    #+#                */
/*   Updated: 2019/09/02 10:06:28 by svoort        ########   odam.nl         */
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

typedef struct			s_linelist
{
	struct tm			time;
	char				*content;
	size_t				content_size;
	struct s_linelist	*next;
	struct s_linelist	*prev;
}						t_linelist;

typedef struct			s_file
{
	char				*tmp_line;
	struct tm			time;
}						t_file;

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

void					print_list(t_linelist *list);
void					print_files(char *folder);
void					add_or_init(t_linelist **list, \
						char *content, struct tm time);

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

char					*ft_printname(struct dirent *dir, \
						struct stat file_stat);
t_file					ft_printfile(char *folder, struct dirent *dir);

/*
**	print_blocks.c
*/

void					print_blocks(char *folder);

/*
**	free.c
*/

void					free_folders(char **folders_to_free);
void					free_lines(t_linelist *lines);

/*
**	solve_shop.c
*/

void					solve_shop(void);

/*
**	linelist.c
*/

t_linelist				*ft_linelstnew(void const *content, \
						size_t content_size, struct tm time);
void					ft_linelstadd(t_linelist **alst, t_linelist *new);

/*
**	sort_list.c
*/

void					sort_list(t_linelist **alst);

/*
**	norminette1.c
*/

void					printname_norme(char **line, char **tmp, \
						struct dirent **dir, struct stat *file_stat);
char					*print_permissions(struct stat file_stat);
char					*print_owner_group(struct stat file_stat);
void					check_and_get_path(struct dirent **dir, \
						char ***paths, int *i, char **folder);
void					print_and_add_to_lines(char *folder, \
						struct dirent *dir, t_linelist **lines);

/*
**	norminette2.c
*/

void					biggie_r_recursion(char **paths, t_linelist *lines);
void					init_variables_to_reduce_lines(char ***paths, \
						t_linelist **lines, DIR **d, char *folder);
void					print_and_sort(t_linelist **lines);
void					print_header(char *folder);

/*
**	block_size.c
*/

int						get_block_size(char *directory);

#endif
