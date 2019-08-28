/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 13:51:56 by svoort         #+#    #+#                */
/*   Updated: 2019/08/28 15:54:56 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_greater_than_next(t_linelist *elem)
{
	if (elem->next)
	{
		if (elem->time.tm_year > elem->next->time.tm_year)
			return (1);
		else if (elem->time.tm_yday > elem->next->time.tm_yday)
			return (1);
		else if (elem->time.tm_hour > elem->next->time.tm_hour)
			return (1);
		else if (elem->time.tm_min > elem->next->time.tm_min)
			return (1);
		else if (elem->time.tm_sec > elem->next->time.tm_sec)
			return (1);
	}
	return (0);
}

static int	is_sorted_t(t_linelist *alst)
{
	t_list	*tmp;

	tmp = alst;
	while (tmp)
	{
		if (is_greater_than_next(tmp) == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}



/*
**	sorts files on time in ascending order.
*/

void	sort_time(t_linelist **alst) 
{
	t_linelist	*tmp;

	while (is_sorted_t(*alst) == 0)
	{
		if (is_greater_than_next(*alst))
		{
			tmp = (*alst)->next;
			(*alst)->next = tmp->next;
			tmp->next = (*alst);
			*alst = tmp;
		}
			
		bubble_sort_t(alst);
	}
}

void	sort_list(t_linelist **alst)
{
	if (g_fl.flags.t)
		sort_time();
}
