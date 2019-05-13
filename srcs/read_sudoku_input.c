/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_sudoku_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 19:04:33 by svoort         #+#    #+#                */
/*   Updated: 2019/05/11 13:55:59 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit_with_char(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < (int)ft_countwords(s, c))
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			str2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = NULL;
	return (str2);
}

char	**read_sudoku_file(int argc, char **argv)
{
	char	**field;
	char	**temp;
	char	buf[91];
	int		fd;
	int		i;

	i = 0;
	if (argc < 3)
		ft_error("Oopsie! No sudoku file given. (./ft_ls -sudoku [sudoku_file])\n");
	fd = open(argv[2], O_RDONLY);
	field = (char**)ft_memalloc(sizeof(char*) * 10);
	field[0] = ft_strdup("/Users/svoort/.brew/bin/sudoku_solver");
	read(fd, buf, 90);
	buf[90] = '\0';
	temp = ft_strsplit(buf, '\n');
	while (temp[i])
	{
		field[i + 1] = ft_strdup(temp[i]);
		i++;
	}
	field[i + 1] = NULL;
	return (field);
}
