/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:58:15 by svoort         #+#    #+#                */
/*   Updated: 2019/08/21 16:24:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_permissions(struct stat file_stat)
{
	ft_printf( (S_ISDIR(file_stat.st_mode)) ? "d" : "-");
	ft_printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
}

static void	print_owner_group(struct stat file_stat)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(file_stat.st_uid);
	gr = getgrgid(file_stat.st_gid);

	ft_printf("%s\t%s\n", pw->pw_name, gr->gr_name);
}

void	print_long_format(char *folder, struct dirent *dir)
{
	struct stat	file_stat;
	char		*path;

	path = get_path(folder, dir->d_name);
	if (stat(path, &file_stat) < 0)
		ft_error("Error getting file information (-l)\n");
	print_permissions(file_stat);
	ft_printf("%4i ", file_stat.st_nlink);
	print_owner_group(file_stat);
}

void	print_short_format(struct dirent *dir)
{
	if (dir->d_type == DT_DIR)
		ft_printf("\e[0;34m%s\n\e[0m", dir->d_name);
	else
		ft_printf("%s\n", dir->d_name);
}

void	ft_printfile(char *folder, struct dirent *dir)
{
	if (g_fl.flags.l == 1)
		print_long_format(folder, dir);
	else
		print_short_format(dir);
}