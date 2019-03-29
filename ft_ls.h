/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:14:30 by svoort         #+#    #+#                */
/*   Updated: 2019/03/29 16:54:43 by svoort        ########   odam.nl         */
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

# define ACC_FLAGS "lRart"

/*
**	store_flags.c
*/

void	store_flags(char *str, int *flags);
int		ft_isflag(char c);

#endif
