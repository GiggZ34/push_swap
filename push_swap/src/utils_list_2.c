/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:20:41 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/01 16:28:21 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*last_list(t_push_swap *p, t_number *lst, int num_lst)
{
	int	i;

	if (!lst)
		return (NULL);
	i = -1;
	while (++i < p->nb_numbers[num_lst] - 1)
		lst = lst->next;
	return (lst);
}

void	swap(t_number **begin, const char *cmd)
{
	t_number	*n1;
	t_number	*n2;

	n1 = *begin;
	n2 = n1->next;
	n1->next = n2->next;
	n1->previous = n2;
	n2->previous = n1->previous;
	n2->next = n1;
	*begin = n2;
	write(1, cmd, ft_strlen(cmd));
}

void	list_add_front(t_number **begin, t_number *new)
{
	new->next = new;
	new->previous = new;
	if (*begin)
	{
		new->previous = (*begin)->previous;
		(*begin)->previous->next = new;
		new->next = *begin;
		(*begin)->previous = new;
	}
	*begin = new;
}

void	list_add_back(t_push_swap *p, t_number **b, t_number *new, int num_lst)
{
	t_number	*lst;
	int			i;

	i = -1;
	lst = *b;
	if (!lst)
		*b = new;
	else
	{
		while (++i < p->nb_numbers[num_lst] - 1)
			lst = lst->next;
		lst->next = new;
		new->previous = lst;
		new->next = *b;
	}
}

int	search_number(t_number *list, int n)
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
