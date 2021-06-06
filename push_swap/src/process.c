/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:06:20 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:06:59 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_2_to_1(t_push_swap *p)
{
	t_number	*lst2;
	int			n;
	int			i;

	if (p->a)
	{
		n = p->a->n;
		lst2 = p->b;
		i = -1;
		while (++i < p->nb_numbers[B])
		{
			if (lst2->n > n)
				return (0);
			lst2 = lst2->next;
		}
	}
	return (1);
}

static int	sort_list(t_push_swap *p, t_number **lst, int num_lst)
{
	t_number	*last;

	last = NULL;
	if (p->nb_numbers[num_lst] > 0 && p->nb_numbers[num_lst] <= 3)
	{
		while (check_sort(p, lst) < p->nb_numbers[A])
		{
			last = last_list(p, *lst, num_lst);
			if ((*lst)->next && (*lst)->n > (*lst)->next->n \
				&& last->n == p->bigger_a[0]->n)
				swap(lst, "sa\n", 1);
			else if ((*lst)->n < last->n && (*lst)->next \
				&& last->n < (*lst)->next->n)
				last_to_first(lst, "rra\n", 1);
			else if ((*lst)->n > last->n)
				first_to_last(lst, "ra\n", 1);
		}
		return (1);
	}
	else if (!p->nb_numbers[num_lst] || check_sort(p, lst) > -1)
		return (turn_list(p, lst, 'a', p->min[0]->n));
	return (0);
}

static int	treatment_lst_a(t_push_swap *p)
{
	int	sort;

	sort = 0;
	if ((p->nb_numbers[A] <= 3 && sort_list(p, &p->a, A)) \
		|| (!p->nb_numbers[B] && check_sort(p, &p->a) > -1))
		return (1);
	return (0);
}

static int	check_list(t_push_swap *p)
{
	if (treatment_lst_a(p) \
		&& (!p->nb_numbers[B] || (asort_list_b(p) && check_asort(p->b)))
		&& check_2_to_1(p))
		return (1);
	return (0);
}

void	process(t_push_swap *p)
{
	while (!check_list(p))
		treatment_list(p);
	while (p->nb_numbers[B])
		switch_number(p, &p->b, &p->a, 1);
}
