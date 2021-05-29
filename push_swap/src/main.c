/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:04:02 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 15:53:39 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_number *l1, t_number *l2)
{
	printf("-----------------------\n");
	printf("\nLIST 1\n");
	while (l1)
	{
		printf("%d\n", l1->n);
		l1 = l1->next;
	}
	printf("\nLIST 2\n");
	while (l2)
	{
		printf("%d\n", l2->n);
		l2 = l2->next;
	}
	printf("------------------------\n");
}

int	main(int ac, char **args)
{
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(t_push_swap));
	push_swap.action = ft_calloc(sizeof(int), 4);
	push_swap.max = ft_calloc(sizeof(t_number *), 3);
	push_swap.min = ft_calloc(sizeof(t_number *), 3);
	if (!push_swap.action || !push_swap.max || !push_swap.min)
		trash_program(&push_swap, ERROR, "Allocation failed\n");
	if (ac > 2)
	{
		numbers_to_list(&push_swap, args + 1, ac - 1);
		process(&push_swap);
	}
	else
		numbers_to_list(&push_swap, args + 1, ac - 1);
	trash_program(&push_swap, SUCCESS, "");
	return (0);
}
