/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:03:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/03 13:16:49 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_location(t_push_swap *p, int n)
{
	t_number	*lst;
	int			range[2];
	int			id;

	lst = p->b;
	range[0] = -1;
	if (p->max[B] && n > p->max[B]->n)
		return (search_number(p->b, p->max[B]->n));
	else if (p->min[B] && n < p->min[B]->n)
		return (search_number(p->b, p->max[B]->n));
	else if (lst->previous->n > n && n > lst->n && lst->n > p->min[B]->n)
		return (0);
	id = -1;
	while (++id < p->nb_numbers[B])
	{
		if (lst->previous->n > n && n > lst->n
			&& (range[0] == -1 || lst->previous->n - lst->n < range[1]))
		{
			range[0] = id;
			range[1] = lst->previous->n - lst->n;
		}
		lst = lst->next;
	}
	return (range[0]);
}

static int	define_actions(int *actions, int *total, int *move_a, int *move_b)
{
	int	dir;

	if (total[RR] <= total[R])
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

static int	search_move_b(t_push_swap *p, t_number *a, int *action, int *move_a)
{
	int	total[2];
	int	move_b[2];

	if (a)
	{
		move_b[R] = search_location(p, a->n);
		total[R] = move_b[R];
		move_b[RR] = p->nb_numbers[B] - move_b[R];
		total[RR] = move_b[RR];
		if (move_a[1] > move_b[move_a[0]])
			total[move_a[0]] += move_a[1] - move_b[move_a[0]];
		total[ft_abs(move_a[0] - 1)] += move_a[1];
		return (define_actions(action, total, move_a, move_b));
	}
	return (trash_program(p, ERROR, "\033[33mProgram failed\033[0m\n"));
}

static void	search_move(t_push_swap *p, int *tmp_actions)
{
	t_number	*a;
	int			move_a[2];

	a = p->a;
	move_a[0] = R;
	move_a[1] = -1;
	while ((move_a[1] < p->nb_numbers[A] \
		&& ((tmp_actions[TOTAL] < 0 || move_a[1] < tmp_actions[TOTAL]))) \
		|| move_a[0] != RR)
	{
		if (++move_a[1] >= tmp_actions[TOTAL] && tmp_actions[TOTAL] >= 0 \
			&& move_a[0] == R)
		{
			a = p->a;
			move_a[0] = RR;
			move_a[1] = 0;
		}
		if (!is_bigger(p, a))
			search_move_b(p, a, tmp_actions, move_a);
		if (move_a[0] == R)
			a = a->next;
		else
			a = a->previous;
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
