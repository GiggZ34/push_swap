/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:20:41 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:14:59 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	switch_number(t_push_swap *p, t_number **l1, t_number **l2, int print)
{
	t_number	*number;
	int			i;
	char		*cmd;

	if (*l2 == p->a)
		cmd = "pa\n";
	else
		cmd = "pb\n";
	i = cmd[1] - 'a';
	number = *l1;
	p->nb_numbers[i]++;
	p->nb_numbers[ft_abs(i - 1)]--;
	if (!p->nb_numbers[ft_abs(i - 1)])
		*l1 = NULL;
	else
	{
		(*l1)->next->previous = number->previous;
		(*l1)->previous->next = number->next;
		*l1 = (*l1)->next;
	}
	max_min_number(p, number, i);
	list_add_front(l2, number);
	if (print)
		write(1, cmd, 3);
	return (0);
}

void	first_to_last(t_number **begin, const char *cmd, int print)
{
	*begin = (*begin)->next;
	if (print)
		write(1, cmd, ft_strlen(cmd));
}

void	last_to_first(t_number **begin, const char *cmd, int print)
{
	*begin = (*begin)->previous;
	if (print)
		write(1, cmd, ft_strlen(cmd));
}

void	add_bigger_number(t_push_swap *p, t_number *n)
{
	t_number	*tmp;

	tmp = NULL;
	if (!p->bigger_a[0] || p->bigger_a[0]->n < n->n)
	{
		tmp = p->bigger_a[0];
		p->bigger_a[0] = n;
	}
	else if (!p->bigger_a[1] || p->bigger_a[1]->n < n->n)
	{
		tmp = p->bigger_a[1];
		p->bigger_a[1] = n;
	}
	else if (!p->bigger_a[2] || p->bigger_a[2]->n < n->n)
	{
		tmp = p->bigger_a[2];
		p->bigger_a[2] = n;
	}
	if (tmp)
		add_bigger_number(p, tmp);
}

int	is_bigger(t_push_swap *p, t_number *n)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (p->bigger_a[i]->n == n->n)
			return (1);
	return (0);
}
