/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:03:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 17:50:57 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_number(t_number *list, int n)
{
	int	id;

	id = 0;
	while (list && list->n != n)
	{
		list = list->next;
		id++;
	}
	return (id);
}

static int	smaller_number(int *action, int n)
{
	int	i;
	int	tmp_id;
	int	tmp_value;

	i = -1;
	tmp_value = INT_MAX;
	while (++i < n)
	{
		if (action[i] >= 0 && (!i || (action[i] < tmp_value)))
		{
			tmp_id = i;
			tmp_value = action[i];
		}
	}
	return (tmp_id);
}

static int	search_location(t_push_swap *p, int n)
{
	t_number	*lst;
	int			id;

	lst = p->first_two;
	id = 1;
	if (lst->n < n && lst->last->n > n)
		return (0);
	else if (p->max[1] && n > p->max[1]->n)
		return (search_number(p->first_two, p->max[1]->n));
	else if (p->min[1] && n < p->min[1]->n)
		return (search_number(p->first_two, p->min[1]->n) + 1);
	while (lst && lst->next && !(lst->n > n && lst->next->n < n))
	{
		id++;
		lst = lst->next;
	}
	return (id);
}

int	generate_actions(t_push_swap *p)
{
	int	count_lst;

	if (p->first_one)
	{
		count_lst = listsize(p->first_two);
		p->action[R] = search_location(p, p->first_one->n);
		p->action[RR] = count_lst - p->action[R];
		if (p->first_one && p->first_one->next)
		{
			p->action[SR] = search_location(p, p->first_one->next->n) + 1;
			p->action[SRR] = count_lst - p->action[SR] + 2;
		}
		return (smaller_number(p->action, NBR_ACTION));
	}
	asort_test(p);
//	print_lst(p->first_one, p->first_two);
	trash_program(p, ERROR, "DEAD\n");
	return (0);
}
