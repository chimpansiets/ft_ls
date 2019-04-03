/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:14:30 by svoort         #+#    #+#                */
/*   Updated: 2019/04/02 15:53:38 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

// Remove some
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h> // <--- like this one
# include <string.h>
# include <stdlib.h>
# include <pwd.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/xattr.h>
# include <locale.h>
# include <grp.h>
# include <langinfo.h>
# include <time.h>
# include <stdint.h>
# include "./libft/libft.h"
# include "./ft_printf/libft.h"

# define ACC_FLAGS "lRart"

typedef struct	s_file {
	char			*filename;
	struct stat		info;
	struct passwd	*pwuser;
	struct group	*grpnam;
	struct s_file	*next;
}				t_file;

/*
**  main.c
*/

int     read_flags(int argc, char **argv);

/*
**	store_flags.c
*/

void	store_flags(char *str, int *flags);
int		ft_isflag(char c);
void    listdir(char *name);

/*
**  ft_listdir.c
*/



#endif
