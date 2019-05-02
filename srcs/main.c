/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:05 by svoort         #+#    #+#                */
/*   Updated: 2019/05/02 18:13:33 by svoort        ########   odam.nl         */
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

	res = 0;
	if (index < 5)
		((char *)(&g_fl->flags))[index] = true;
	else
		res = ft_printf("%s%c\n%s", "./ft_ls: illegal option -- ", flag, \
		"usage: ./ft_ls [-AGRadefgilprstu1@] [file ...]\n");
	return (res != 0);
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
				if (assign_flag(argv[index][i]))
					return (-1);
				i++;
			}
			index++;
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		i;

	g_fl = (t_fl*)ft_memalloc(sizeof(t_fl));
	i = parse_flags(argc, argv);
	if (i != -1)
	{
		// doe die tknewie
		// is wel zo
		// ls_trash();
	}
	return (argc);
}
