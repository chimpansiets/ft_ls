/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norminette1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 10:41:29 by svoort         #+#    #+#                */
/*   Updated: 2019/09/20 13:59:18 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printname_norme(char **line, char **tmp, \
			struct dirent **dir, struct stat *file_stat)
{
	(*line) = ft_joinfree(*line, *tmp, 3);
	(*tmp) = ft_printname(*dir, *file_stat);
	(*line) = ft_joinfree(*line, *tmp, 3);
}

char		*print_permissions(struct stat file_stat)
{
	char	*line;

	line = ft_strdup((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
	line = ft_joinfree(line, (file_stat.st_mode & S_IRUSR) ? "r" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IWUSR) ? "w" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IXUSR) ? "x" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IRGRP) ? "r" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IWGRP) ? "w" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IXGRP) ? "x" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IROTH) ? "r" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IWOTH) ? "w" : "-", 1);
	line = ft_joinfree(line, (file_stat.st_mode & S_IXOTH) ? "x" : "-", 1);
	line = ft_joinfree(line, " ", 1);
	return (line);
}

char		*print_owner_group(struct stat file_stat)
{
	char			*ret;
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(file_stat.st_uid);
	gr = getgrgid(file_stat.st_gid);
	ret = (char *)ft_memalloc(sizeof(char) * 256);
	sprintf(ret, "%s\t%s ", pw->pw_name, gr->gr_name);
	return (ret);
}

void		check_and_get_path(struct dirent **dir, \
			char ***paths, int *i, char **folder)
{
	if ((*dir)->d_type == DT_DIR && g_fl.flags.biggie_r == 1 && \
	!ft_strequ((*dir)->d_name, ".") && !ft_strequ((*dir)->d_name, ".."))
		(*paths)[(*i)++] = get_path(*folder, (*dir)->d_name);
}

void		print_and_add_to_lines(char *folder, struct dirent *dir, \
			t_linelist **lines)
{
	t_file		tmp_file;

	tmp_file = ft_printfile(folder, dir);
	add_or_init(lines, tmp_file.tmp_line, tmp_file.time, dir->d_name);
	free(tmp_file.tmp_line);
}
