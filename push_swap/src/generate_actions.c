/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:03:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/30 20:40:59 by grivalan         ###   ########lyon.fr   */
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

	lst = p->b;
	id = 1;
	if (lst && lst->n < n && lst->last->n > n)
		return (0);
	else if (p->max[1] && n > p->max[1]->n)
		return (search_number(p->b, p->max[1]->n));
	else if (p->min[1] && n < p->min[1]->n)
		return (search_number(p->b, p->min[1]->n) + 1);
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

	if (p->a)
	{
		count_lst = listsize(p->b);
		p->action[R] = search_location(p, p->a->n);
		p->action[RR] = count_lst - p->action[R];
		if (p->a && p->a->next)
		{
			p->action[SR] = search_location(p, p->a->next->n) + 1;
			p->action[SRR] = count_lst - p->action[SR] + 2;
		}
		return (smaller_number(p->action, NBR_ACTION));
	}
	asort_test(p);
	trash_program(p, ERROR, "DEAD\n");
	return (0);
}

int	define_actions(int *actions, int *total, int *move_a, int *move_b)
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
	int	count_lst;
	int	dir;

	if (move_a[0] == R)
		dir = RR;
	else
		dir = R;
	if (a)
	{
		count_lst = listsize(p->b);
		move_b[R] = search_location(p, a->n);
		total[R] = move_b[R];
		move_b[RR] = count_lst - move_b[R];
		total[RR] = move_b[RR];
		total[dir] += move_a[1];
		return (define_actions(actions, total, move_a, move_b));
	}
	return (trash_program(p, ERROR, "Program failed\n"));
}

t_number	*traitement_list(t_push_swap *p, t_number *n, int dir)
{
	t_number	*tmp;

	tmp = n;
	if (dir == R)
		n = n->next;
	else
		n = n->previous;
	n->last = p->last_a;
	return (n);
}

void	search_move(t_push_swap *p, int *tmp_actions)
{
	t_number	*a;
	int			move_a[2];

	a = p->a;
	move_a[0] = R;
	move_a[1] = -1;
	while (a && ((tmp_actions[TOTAL] < 0 || move_a[1] < tmp_actions[TOTAL]) && move_a[0] != RR))
	{
		if (++move_a[1] >= tmp_actions[TOTAL] && tmp_actions[TOTAL] >= 0 && move_a[0] == R)
		{
			a = p->a;
			move_a[1] = 0;
			move_a[0] = RR;
		}
		search_move_b(p, a, tmp_actions, move_a);
		a = traitement_list(p, a, move_a[0]);
		printf("i = %d\n", move_a[1]);
		printf("-- %d -- %d ==> %d || %d ==> %d\n", tmp_actions[TOTAL], tmp_actions[DIR_A], tmp_actions[NB_A], tmp_actions[DIR_B], tmp_actions[NB_B]);
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
		printf("-- %d -- %d ==> %d || %d ==> %d\n", p->action[TOTAL], p->action[DIR_A], p->action[NB_A], p->action[DIR_B], p->action[NB_B]);
	trash_program(p, ERROR, "test\n");
	return (0);
}
