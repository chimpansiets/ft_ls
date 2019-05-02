/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_sudoku_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 19:04:33 by svoort         #+#    #+#                */
/*   Updated: 2019/05/02 19:07:03 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_input(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (ft_isdigit(buf[i]) && ft_isspace(buf[i]))
			i += 2;
		else
			ft_error("Sudoku file is corrupted.\n");
	}
}

short	*parse_input(char *buf)
{
	ft_check_input(buf);
}

short	**read_sudoku_file(int argc, char **argv)
{
	short	**field;
	char	buf[19];
	int		fd;
	int		i;

	i = 0;
	if (argc < 3)
		ft_error("Oopsie! No sudoku file given.\n");
	fd = open(argv[3], O_RDONLY);
	while (get_next_line(fd, &buf))
	{
		field[i] = parse_input(buf);
		i++;
	}
}
