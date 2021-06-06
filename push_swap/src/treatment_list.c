/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:59:39 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:08:45 by grivalan         ###   ########lyon.fr   */
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
		first_to_last(lst, print, 1);
	}
	else
	{
		print[1] = 'r';
		print[2] = alpha;
		print[3] = '\n';
		last_to_first(lst, print, 1);
	}
}

static void	double_actions(t_push_swap *p)
{
	if (p->action[DIR_A] == R)
	{
		first_to_last(&p->a, "r", 1);
		first_to_last(&p->b, "r\n", 1);
	}
	else
	{
		last_to_first(&p->a, "r", 1);
		last_to_first(&p->b, "rr\n", 1);
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
		switch_number(p, &p->a, &p->b, 1);
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
				switch_number(p, &p->a, &p->b, 1);
				nb++;
			}
			else
				first_to_last(&p->a, "ra\n", 1);
		}
	}
	else
	{
		search_actions(p);
		exect_action(p);
	}
	return (0);
}
