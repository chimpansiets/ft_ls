/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_sudoku_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 19:04:33 by svoort         #+#    #+#                */
/*   Updated: 2019/05/10 16:58:37 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**read_sudoku_file(int argc, char **argv)
{
	char	**field;
	char	*buf;
	int		fd;
	int		i;
	int		ret;

	i = 0;
	field = (char**)ft_memalloc(sizeof(char*) * 10);
	if (argc < 3)
		ft_error("Oopsie! No sudoku file given.\n");
	fd = open(argv[2], O_RDONLY);
	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		buf[ret] = '\0';
		field[i] = ft_strdup(buf);
		i++;
	}
	field[i] = NULL;
	i = 0;
	while (i++ < 9)
		printf("%s\n", field[i]);
	return (field);
}
