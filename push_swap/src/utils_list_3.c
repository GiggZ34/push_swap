/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:12:48 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:58:46 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_min_number(t_push_swap *p, t_number *number, int i)
{
	if (!p->max[i] || p->max[i]->n < number->n)
		p->max[i] = number;
	if (!p->min[i] || p->min[i]->n > number->n)
		p->min[i] = number;
}

void	print_lst(t_push_swap *p)
{
	t_number	*lst;
	int			i;

	write(2, "_______________LST1_______________\n", 35);
	lst = p->a;
	i = -1;
	while (++i < p->nb_numbers[A])
	{
		ft_putnbr_fd(lst->n, 2);
		write(2, "\n", 1);
		lst = lst->next;
	}
	write(2, "_______________LST2_______________\n", 35);
	lst = p->b;
	i = -1;
	while (++i < p->nb_numbers[B])
	{
		ft_putnbr_fd(lst->n, 2);
		write(2, "\n", 1);
		lst = lst->next;
	}
}
