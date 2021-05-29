/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:06:20 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 16:30:27 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_2_to_1(t_push_swap *p)
{
	t_number	*lst2;
	int			n;

	n = p->first_one->n;
	lst2 = p->first_two;
	while (lst2)
	{
		if (lst2->n > n)
			return (0);
		lst2 = lst2->next;
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

	size_lst1 = listsize(p->first_one);
	size_lst2 = listsize(p->first_two);
	if (!size_lst2)
	{
		p->dir = 0;
		return (check_sort(p->first_one));
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
	while (!check_list(p))
	{
		if (check_sort(p->first_one) && check_asort(p->first_two) \
			&& check_2_to_1(p))
		{
			while (p->first_two)
				switch_number(p, &p->first_two, &p->first_one, 'a');
		}
		else
		{
			ft_memset(p->action, CHAR_MAX, sizeof(int) * 4);
			if (p->first_one)
				p->first_one->last = last_list(p->first_one);
			if (p->first_two)
				p->first_two->last = last_list(p->first_two);
			treatment_list(p);
		}
	// print_lst(p->first_one, p->first_two);
	}
	// print_lst(p->first_one, p->first_two);
}
