/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:59:39 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/30 20:38:35 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	nb_actions_list_a(t_push_swap *p, int id, int n_actions)
{
	t_number	*number;
	int			i;
	int			id_tmp;
	int			tmp_diff;

	number = p->a;
	tmp_diff = INT_MAX;
	id_tmp = 0;
	i = -1;
	while (++i < n_actions)
	{
		if (id == RR || id == SRR)
		{
			number = number->previous;
			if (ft_abs(p->a->n - number->n) < tmp_diff)
			{
				tmp_diff = ft_abs(p->a->n - number->n);
				id_tmp = i;
			}
		}
		else if (id == R || id == SR)
		{
			number = number->next;
			if (ft_abs(p->a->n - number->n) < tmp_diff)
			{
				tmp_diff = ft_abs(p->a->n - number->n);
				id_tmp = i;
			}
		}
	}
	return (id_tmp);
}

static void	exect_action(t_push_swap *p, int id, int n_actions)
{
	int	i;

	if (id == SR || id == SRR)
	{
		swap(&p->a, "sa\n");
		n_actions--;
	}
	i = -1;
	while (++i < n_actions)
	{
		if (id == RR | id == SRR)
			last_to_first(&p->b, "rrb\n");
		else
			first_to_last(&p->b, "rb\n");
	}
	switch_number(p, &p->a, &p->b, 'b');
}
*/
int	treatment_list(t_push_swap *p)
{
//	int	id;

	if (listsize(p->b) >= 2)
	{
		search_actions(p);
//		id = generate_actions(p);
//		exect_action(p, id, p->action[id]);
	}
	else
	{
		switch_number(p, &p->a, &p->b, 'b');
		switch_number(p, &p->a, &p->b, 'b');
		if (p->b->n < p->b->next->n)
			swap(&p->b, "sb\n");
	}
	return (0);
}




void	asort_test(t_push_swap *p)
{
	while (p->b->n != p->max[1]->n)
		last_to_first(&p->b, "rrb\n");
}
