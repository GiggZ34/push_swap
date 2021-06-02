/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:59:39 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/02 17:09:33 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	single_action(t_number **lst, char dir, char alpha)
{
	char	print[5];

	print[0] = 'r';
	print[4] = '\0';
	if (dir == R)
	{
		print[1] = alpha;
		print[2] = '\n';
		print[3] = '\0';
		first_to_last(lst, print);
	}
	else
	{
		print[1] = 'r';
		print[2] = alpha;
		print[3] = '\n';
		last_to_first(lst, print);
	}
}

static void	double_actions(t_push_swap *p)
{
	if (p->action[DIR_A] == R)
	{
		first_to_last(&p->a, "r");
		first_to_last(&p->b, "r\n");
	}
	else
	{
		last_to_first(&p->a, "r");
		last_to_first(&p->b, "rr\n");
	}
}

static void	exect_action(t_push_swap *p)
{
	while (p->action[NB_A] > 0 || p->action[NB_B] > 0)
	{
		if (p->action[DIR_A] == p->action[DIR_B] \
			&& p->action[NB_A] > 0 && p->action[NB_B] > 0)
			double_actions(p);
		else
		{
			if (p->action[NB_A] > 0)
				single_action(&p->a, p->action[DIR_A], 'a');
			if (p->action[NB_B] > 0)
				single_action(&p->b, p->action[DIR_B], 'b');
		}
		p->action[NB_A]--;
		p->action[NB_B]--;
	}
	if (p->a)
		switch_number(p, &p->a, &p->b, "pb\n");
}

int	treatment_list(t_push_swap *p)
{
	int	nb;

	nb = 0;
	if (!p->nb_numbers[B])
	{
		while (nb < 2)
		{
			if (!is_bigger(p, p->a))
			{
				switch_number(p, &p->a, &p->b, "pb\n");
				nb++;
			}
			else
				first_to_last(&p->a, "ra\n");
		}
	}
	else
	{
		search_actions(p);
		exect_action(p);
	}
	return (0);
}

int	asort_list_b(t_push_swap *p)
{
	t_number	*l;
	int			id;

	l = p->b;
	id = search_number(p->b, p->max[1]->n);
	while (l->n < p->max[1]->n)
	{
		id++;
		l = l->next;
	}
	while (p->b->n != p->max[1]->n)
	{
		if (id <= p->nb_numbers[B] - id)
			first_to_last(&p->b, "rb\n");
		else
			last_to_first(&p->b, "rrb\n");
	}
	return (1);
}
