/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:04:02 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/02 17:45:39 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_push_swap *p)
{
	t_number	*l1;
	t_number	*l2;
	int			i;

	dprintf(2, "-----------------------\n");
	dprintf(2, "\nLIST 1\n");
	l1 = p->a;
	l2 = p->b;
	i = -1;
	while (p->nb_numbers[A] && ++i < p->nb_numbers[A])
	{
		dprintf(2, "%d - ", l1->n);
		l1 = l1->next;
	}
	dprintf(2, "\n");
	dprintf(2, "\nLIST 2\n");
	i = -1;
	while (p->nb_numbers[B] && ++i < p->nb_numbers[B])
	{
		dprintf(2, "%d - ", l2->n);
		l2 = l2->next;
	}
	dprintf(2, "\n");
}

static void	init_push_swap(t_push_swap *p)
{
	p->action = ft_calloc(sizeof(int), 5);
	p->max = ft_calloc(sizeof(t_number *), 3);
	p->min = ft_calloc(sizeof(t_number *), 3);
	p->nb_numbers = ft_calloc(sizeof(int), 2);
	p->bigger_a = ft_calloc(sizeof(t_number *), 3);
	if (!p->action || !p->max \
		|| !p->min || !p->nb_numbers)
		trash_program(p, ERROR, "Allocation failed\n");
}

int	main(int ac, char **args)
{
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(t_push_swap));
	init_push_swap(&push_swap);
	if (ac > 1)
	{
		numbers_to_list(&push_swap, args + 1, ac - 1);
		process(&push_swap);
	}
	// print_lst(&push_swap);
	trash_program(&push_swap, SUCCESS, "");
	return (0);
}
