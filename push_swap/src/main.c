/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:04:02 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:59:05 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_push_swap(t_push_swap *p)
{
	p->action = ft_calloc(sizeof(int), 5);
	p->max = ft_calloc(sizeof(t_number *), 3);
	p->min = ft_calloc(sizeof(t_number *), 3);
	p->nb_numbers = ft_calloc(sizeof(int), 2);
	p->bigger_a = ft_calloc(sizeof(t_number *), 3);
	if (!p->action || !p->max \
		|| !p->min || !p->nb_numbers)
		trash_program(p, ERROR, "\033[33mAllocation failed\033[0m\n");
}

int	main(int ac, char **args)
{
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(t_push_swap));
	init_push_swap(&push_swap);
	if (!ft_strncmp(args[1], "--error\0", 8) || !ft_strncmp(args[1], "-e\0", 3))
	{
		push_swap.error_return = 1;
		ac--;
		args++;
	}
	if (!ft_strncmp(args[1], "--print\0", 8) || !ft_strncmp(args[1], "-p\0", 3))
	{
		push_swap.print_lst = 1;
		ac--;
		args++;
	}
	if (ac > 1)
	{
		numbers_to_list(&push_swap, args + 1, ac - 1);
		process(&push_swap);
	}
	if (push_swap.print_lst)
		print_lst(&push_swap);
	trash_program(&push_swap, SUCCESS, "");
	return (0);
}
