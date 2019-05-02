/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:05 by svoort         #+#    #+#                */
/*   Updated: 2019/05/01 18:15:11 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define FLAG_S	5

static inline short	assign_flag(char flag)
{
	const char			chars[FLAG_S] = "lRart";
	const char			j[2] = {flag, 0};
	const size_t		index = ft_strstr(chars, j) - chars;
	int					res;

	if (flag == chars[0])
	res = 0;
}

static inline int	parse_flags(int argc, char **argv)
{
	int		index;
	int		i;

	index = 1;
	if (!ft_check_bonus_flags(argc, argv))
	{
		while (argv[index] && argv[index][0] == '-' && argv[index][1])
		{
			i = 1;
			while (argv[index][i])
			{
				assign_flag(argv[index][i]);
			}
			index++;
		}
	}
}

int main(int argc, char **argv)
{
	int		i;

	i = parse_flags(argc, argv);
	if (i != -1)
	{
		// doe die tknewie
		// is wel zo
		ls_trash();
	}
	return (argc);
}
