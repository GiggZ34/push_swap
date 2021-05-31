/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:03:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/31 19:57:45 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_location(t_push_swap *p, int n)
{
	t_number	*lst;
	int			id;

	lst = p->b;
	id = 1;
	if (lst->n < n && lst->previous->n > n)
		return (0);
	else if (p->max[1] && n > p->max[1]->n)
		return (search_number(p->b, p->max[1]->n));
	else if (p->min[1] && n < p->min[1]->n)
		return (search_number(p->b, p->min[1]->n) + 1);
	while (lst->next && !(lst->n > n && lst->next->n < n))
	{
		id++;
		lst = lst->next;
	}
	return (id);
}

static int	define_actions(int *actions, int *total, int *move_a, int *move_b)
{
	int	dir;

	if (total[RR] < total[R])
		dir = RR;
	else
		dir = R;
	if (actions[TOTAL] >= 0 && actions[TOTAL] <= total[dir])
		return (0);
	actions[TOTAL] = total[dir];
	actions[DIR_A] = move_a[0];
	actions[NB_A] = move_a[1];
	actions[DIR_B] = dir;
	actions[NB_B] = move_b[dir];
	return (0);
}

int	search_move_b(t_push_swap *p, t_number *a, int *actions, int *move_a)
{
	int	total[2];
	int	move_b[2];
	int	dir;

	if (move_a[0] == R)
		dir = RR;
	else
		dir = R;
	if (a)
	{
		move_b[R] = search_location(p, a->n);
		total[R] = move_b[R];
		move_b[RR] = p->nb_numbers[B] - move_b[R];
		total[RR] = move_b[RR];
		total[dir] += move_a[1];
		return (define_actions(actions, total, move_a, move_b));
	}
	return (trash_program(p, ERROR, "Program failed\n"));
}

void	search_move(t_push_swap *p, int *tmp_actions)
{
	t_number	*a;
	int			move_a[2];

	a = p->a;
	move_a[0] = R;
	move_a[1] = -1;
	while (a && ((tmp_actions[TOTAL] < 0 || move_a[1] < tmp_actions[TOTAL]) \
		&& move_a[0] != RR))
	{
		if (++move_a[1] >= tmp_actions[TOTAL] && tmp_actions[TOTAL] >= 0 \
			&& move_a[0] == R)
		{
			a = p->a;
			move_a[1] = 0;
			move_a[0] = RR;
		}
		search_move_b(p, a, tmp_actions, move_a);
		if (move_a[0] == R)
			a = a->next;
		else
			a = a->previous;
		if (!tmp_actions[TOTAL])
			return ;
	}
}

int	search_actions(t_push_swap *p)
{
	int	tmp_actions[5];

	ft_memset(tmp_actions, -1, sizeof(int) * 5);
	search_move(p, tmp_actions);
	ft_memcpy(p->action, tmp_actions, sizeof(int) * 5);
	return (0);
}
