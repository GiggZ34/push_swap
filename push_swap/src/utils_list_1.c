/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:20:41 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 18:08:19 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	switch_number(t_push_swap *p, t_number **l1, t_number **l2, char c)
{
	t_number	*number;
	int			i;

	number = *l1;
	i = c - 'a';
	if (!p->max[i] || p->max[i]->n < number->n)
		p->max[i] = number;
	else if (!p->min[i] || p->min[i]->n > number->n)
		p->min[i] = number;
	*l1 = number->next;
	list_add_front(l2, number);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}

void	first_to_last(t_number **begin, const char *cmd)
{
	t_number	*first;

	first = (*begin);
	(*begin) = (*begin)->next;
	list_add_back(begin, first);
	write(1, cmd, ft_strlen(cmd));
}

void	last_to_first(t_number **begin, const char *cmd)
{
	t_number	*last;
	t_number	*before_last;

	last = last_list(*begin);
	before_last = before_last_list(*begin);
	before_last->next = NULL;
	list_add_front(begin, last);
	write(1, cmd, ft_strlen(cmd));
}

t_number	*before_last_list(t_number *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	listsize(t_number *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
