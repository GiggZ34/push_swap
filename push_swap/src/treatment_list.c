/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:59:39 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 18:44:33 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nb_actions_list_a(t_push_swap *p, int id, int n_actions)
{
	t_number	*number;
	int			i;
	int			id_tmp;
	int			tmp_diff;

	number = p->first_one;
	tmp_diff = INT_MAX;
	id_tmp = 0;
	i = -1;
	while (++i < n_actions)
	{
		if (id == RR || id == SRR)
		{
			number = number->previous;
			if (ft_abs(p->first_one->n - number->n) < tmp_diff)
			{
				tmp_diff = ft_abs(p->first_one->n - number->n);
				id_tmp = i;
			}
		}
		else if (id == R || id == SR)
		{
			number = number->next;
			if (ft_abs(p->first_one->n - number->n) < tmp_diff)
			{
				tmp_diff = ft_abs(p->first_one->n - number->n);
				id_tmp = i;
			}
		}
	}
	return (id_tmp);
}

static void	exect_action(t_push_swap *p, int id, int n_actions)
{
	int	i;
	int	j;

	if (id == SR || id == SRR)
	{
		swap(&p->first_one, "sa\n");
		n_actions--;
	}
	i = -1;
	if (listsize(p->first_one) > 1)
		j = nb_actions_list_a(p, id, n_actions);
	else
		j = 0;
	printf("%d\n", j);
	while (++i < n_actions)
	{
		if (id == RR | id == SRR)
			last_to_first(&p->first_two, "rrb\n");
		else
			first_to_last(&p->first_two, "rb\n");
	}
	switch_number(p, &p->first_one, &p->first_two, 'b');
}

void	asort_test(t_push_swap *p)
{
	while (p->first_two->n != p->max[1]->n)
		last_to_first(&p->first_two, "rrb\n");
}

int	treatment_list(t_push_swap *p)
{
	int	id;

	if (listsize(p->first_two) >= 2)
	{
		id = generate_actions(p);
		exect_action(p, id, p->action[id]);
	}
	else
	{
		switch_number(p, &p->first_one, &p->first_two, 'b');
		switch_number(p, &p->first_one, &p->first_two, 'b');
		if (p->first_two->n < p->first_two->next->n)
			swap(&p->first_two, "sb\n");
	}
	return (0);
}
