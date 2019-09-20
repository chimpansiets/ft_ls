/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 13:51:56 by svoort         #+#    #+#                */
/*   Updated: 2019/09/20 14:33:11 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		is_greater_than_next(t_linelist *elem)
{
	if (elem->next)
	{
		if (elem->time.tm_year > elem->next->time.tm_year)
			return (1);
		else if (elem->time.tm_year < elem->next->time.tm_year)
			return (0);
		else if (elem->time.tm_yday > elem->next->time.tm_yday)
			return (1);
		else if (elem->time.tm_yday < elem->next->time.tm_yday)
			return (0);
		else if (elem->time.tm_hour > elem->next->time.tm_hour)
			return (1);
		else if (elem->time.tm_hour < elem->next->time.tm_hour)
			return (0);
		else if (elem->time.tm_min > elem->next->time.tm_min)
			return (1);
		else if (elem->time.tm_min < elem->next->time.tm_min)
			return (0);
		else if (elem->time.tm_sec > elem->next->time.tm_sec)
			return (1);
		else if (elem->time.tm_sec < elem->next->time.tm_sec)
			return (0);
	}
	return (0);
}

/*
**	sorts files on time in ascending order.
*/

static void		swap(t_linelist *a, t_linelist *b)
{
	struct tm	time_tmp;
	char		*content_tmp;
	char		*filename_tmp;
	size_t		content_size_tmp;

	time_tmp = a->time;
	filename_tmp = a->filename;
	content_tmp = a->content;
	content_size_tmp = a->content_size;
	a->time = b->time;
	a->filename = b->filename;
	a->content = b->content;
	a->content_size = b->content_size;
	b->time = time_tmp;
	b->filename = filename_tmp;
	b->content = content_tmp;
	b->content_size = content_size_tmp;
}

static void		sort_time(t_linelist **alst)
{
	int				swapped;
	t_linelist		*ptr1;
	t_linelist		*lptr;

	lptr = NULL;
	if ((*alst) == NULL)
		return ;
	swapped = 1;
	ptr1 = (*alst);
	while (swapped)
	{
		swapped = 0;
		ptr1 = (*alst);
		while (ptr1->next != lptr)
		{
			if (is_greater_than_next(ptr1))
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

static void		sort_ascii(t_linelist **alst)
{
	int				swapped;
	t_linelist		*ptr1;
	t_linelist		*lptr;

	lptr = NULL;
	if ((*alst) == NULL)
		return ;
	swapped = 1;
	ptr1 = (*alst);
	while (swapped)
	{
		swapped = 0;
		ptr1 = (*alst);
		while (ptr1->next != lptr)
		{
			if (ft_strcmp(ptr1->filename, ptr1->next->filename) < 0)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

void			sort_list(t_linelist **alst)
{
	if (g_fl.flags.t)
		sort_time(alst);
	else
		sort_ascii(alst);
}
