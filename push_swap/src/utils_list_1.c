/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:20:41 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/31 19:51:27 by grivalan         ###   ########lyon.fr   */
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
	if (!p->min[i] || p->min[i]->n > number->n)
		p->min[i] = number;
	*l1 = number->next;
	list_add_front(l2, number);
	p->nb_numbers[i]++;
	i = ft_abs(i - 1);
	p->nb_numbers[i]--;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}

void	first_to_last(t_number **begin, const char *cmd)
{
	*begin = (*begin)->next;
	write(1, cmd, ft_strlen(cmd));
}

void	last_to_first(t_number **begin, const char *cmd)
{
	*begin = (*begin)->previous;
	write(1, cmd, ft_strlen(cmd));
}
