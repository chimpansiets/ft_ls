/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:58:15 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 10:52:58 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*print_date_time(struct stat file_stat, t_file *file)
{
	struct tm	tm_file;
	struct tm	tm_now;
	char		*ret;
	char		time_str[64];
	time_t		now;

	now = time(NULL);
	localtime_r(&file_stat.st_mtime, &tm_file);
	localtime_r(&file_stat.st_mtime, &tm_now);
	ret = ft_memalloc(sizeof(char) * 256);
	file->time = tm_file;
	if (tm_file.tm_year == tm_now.tm_year)
	{
		strftime(time_str, sizeof(time_str), "%b %e %H:%M", &tm_file);
		sprintf(ret, "%s ", time_str);
		return (ret);
	}
	else
	{
		strftime(time_str, sizeof(time_str), "%b %e  %Y", &tm_file);
		sprintf(ret, "%s ", time_str);
		return (ret);
	}
}

char			*ft_printname(struct dirent *dir, struct stat file_stat)
{
	char	*ret;

	ret = NULL;
	if (dir->d_type == DT_DIR && (file_stat.st_mode & S_IXOTH) == 1)
		ret = ft_strdup("\e[1;36m");
	else if ((file_stat.st_mode & S_IXOTH) == 1)
		ret = ft_strdup("\e[0;31m");
	if (ret)
	{
		ret = ft_joinfree(ret, dir->d_name, 1);
		ret = ft_joinfree(ret, "\e[0m", 1);
	}
	else
		ret = ft_strdup(dir->d_name);
	return (ret);
}

static t_file	print_long_format(char *folder, struct dirent *dir)
{
	struct stat	file_stat;
	t_file		file;
	char		*path;
	char		*line;
	char		*tmp;

	line = ft_memalloc(1);
	path = get_path(folder, dir->d_name);
	if (stat(path, &file_stat) < 0)
		ft_error("Error getting file information (-l)\n");
	tmp = print_permissions(file_stat);
	line = ft_joinfree(line, tmp, 3);
	tmp = ft_memalloc(sizeof(char) * 256);
	sprintf(tmp, "%4i ", file_stat.st_nlink);
	line = ft_joinfree(line, tmp, 3);
	tmp = print_owner_group(file_stat);
	line = ft_joinfree(line, tmp, 3);
	tmp = (char *)ft_memalloc(sizeof(char) * 256);
	sprintf(tmp, "%6lli ", file_stat.st_size);
	line = ft_joinfree(line, tmp, 3);
	tmp = print_date_time(file_stat, &file);
	printname_norme(&line, &tmp, &dir, &file_stat);
	free(path);
	file.tmp_line = line;
	return (file);
}

static t_file	print_short_format(struct dirent *dir)
{
	t_file		file;
	char		*line;
	struct stat	file_stat;
	struct tm	time;

	if (dir->d_type == DT_DIR)
	{
		line = ft_strdup("\e[1;36m");
		line = ft_joinfree(line, dir->d_name, 1);
		line = ft_joinfree(line, "\e[0m", 1);
	}
	else
		line = ft_strdup(dir->d_name);
	stat(dir->d_name, &file_stat);
	localtime_r(&file_stat.st_mtime, &time);
	file.tmp_line = line;
	file.time = time;
	return (file);
}

t_file			ft_printfile(char *folder, struct dirent *dir)
{
	t_file	file;

	if (g_fl.flags.l == 1)
		file = print_long_format(folder, dir);
	else
		file = print_short_format(dir);
	return (file);
}
