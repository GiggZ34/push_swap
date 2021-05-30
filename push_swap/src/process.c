/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:06:20 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/30 20:01:26 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_2_to_1(t_push_swap *p)
{
	t_number	*lst2;
	int			n;

	if (p->a)
	{
		n = p->a->n;
		lst2 = p->b;
		while (lst2)
		{
			if (lst2->n > n)
				return (0);
			lst2 = lst2->next;
		}
	}
	return (1);
}

static int	check_asort(t_number *lst)
{
	int	tmp;

	if (lst)
	{
		tmp = lst->n;
		lst = lst->next;
		while (lst)
		{
			if (tmp < lst->n)
				return (0);
			tmp = lst->n;
			lst = lst->next;
		}
	}
	return (1);
}

static int	check_sort(t_number *lst)
{
	int	tmp;

	if (lst)
	{
		tmp = lst->n;
		lst = lst->next;
		while (lst)
		{
			if (tmp > lst->n)
				return (0);
			tmp = lst->n;
			lst = lst->next;
		}
	}
	return (1);
}

static int	check_list(t_push_swap *p)
{
	int	size_lst1;
	int	size_lst2;

	size_lst1 = listsize(p->a);
	size_lst2 = listsize(p->b);
	if (!size_lst2)
	{
		p->dir = 0;
		return (check_sort(p->a));
	}
	else if (!size_lst1)
	{
		p->dir = 1;
		return (0);
	}
	return (0);
}

void	process(t_push_swap *p)
{
	p->nub_numbers = listsize(p->a);
	while (!check_list(p))
	{
		if (check_sort(p->a) && check_asort(p->b) \
			&& check_2_to_1(p))
		{
			while (p->b)
			{
				switch_number(p, &p->b, &p->a, 'a');
			}
		}
		else
		{
			ft_memset(p->action, CHAR_MAX, sizeof(int) * 4);
			if (p->a)
				p->a->last = last_list(p->a);
			if (p->b)
				p->b->last = last_list(p->b);
			if (p->a && p->a->next)
				p->a->next->last = p->a->last;
			if (p->b && p->b->next)
				p->b->next->last = p->b->last;
			treatment_list(p);
		}
	// print_lst(p->a, p->b);
	}
	 print_lst(p->a, p->b);
}
