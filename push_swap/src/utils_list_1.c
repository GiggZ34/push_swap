/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:20:41 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/01 02:20:48 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	switch_number(t_push_swap *p, t_number **l1, t_number **l2, char *cmd)
{
	t_number	*number;
	int			i;

	i = cmd[1] - 'a';
	number = *l1;
	p->nb_numbers[i]++;
	p->nb_numbers[ft_abs(i - 1)]--;
	if (!p->nb_numbers[ft_abs(i - 1)])
		*l1 = NULL;
	else
	{
		*l1 = (*l1)->next;
		(*l1)->previous = (*l1)->previous->previous;
	}
	if (!p->max[i] || p->max[i]->n < number->n)
		p->max[i] = number;
	if (!p->min[i] || p->min[i]->n > number->n)
		p->min[i] = number;
	list_add_front(l2, number);
	write(1, cmd, 3);
	return (0);
}

void	first_to_last(t_number **begin, const char *cmd)
{
	*begin = (*begin)->previous;
	write(1, cmd, ft_strlen(cmd));
}

void	last_to_first(t_number **begin, const char *cmd)
{
	*begin = (*begin)->next;
	write(1, cmd, ft_strlen(cmd));
}
