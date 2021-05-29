/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:20:41 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 18:11:37 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*last_list(t_number *lst)
{
	while (lst->next)
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
	n2->next = n1;
	n2->previous = n1->last;
	*begin = n2;
	write(1, cmd, ft_strlen(cmd));
}

void	list_add_front(t_number **begin, t_number *new)
{
	new->next = *begin;
	if (*begin)
	{
		new->last = new->next->last;
		new->previous = new->last;
	}
	*begin = new;
}

void	list_add_back(t_number **begin, t_number *new)
{
	t_number	*lst;

	new->next = NULL;
	lst = *begin;
	if (!lst)
		*begin = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		new->previous = lst;
		lst->next = new;
	}
}
