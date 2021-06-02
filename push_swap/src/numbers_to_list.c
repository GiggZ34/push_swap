/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:29:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/02 11:52:28 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' && !ft_isdigit(str[i + 1])) \
		|| (str[i] != '-' && !ft_isdigit(str[i])))
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

static int	check_duplicate(t_push_swap *p, t_number *lst, t_number *check)
{
	int	i;

	i = -1;
	while (++i < p->nb_numbers[A])
	{
		if (lst->n == check->n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void	add_list(t_push_swap *p, int n)
{
	t_number	*number;

	number = ft_calloc(sizeof(t_number), 1);
	if (!number)
		trash_program(p, ERROR, "Allocation failed\n");
	number->n = n;
	if (check_duplicate(p, p->a, number))
	{
		free(number);
		trash_program(p, ERROR, "Number duplicate\n");
	}
	add_bigger_number(p, number);
	list_add_back(p, &(p->a), number, A);
}

int	numbers_to_list(t_push_swap *p, char **tab, int n)
{
	long	number;

	p->nb_numbers[A] = -1;
	while (++p->nb_numbers[A] < n)
	{
		number = ft_atoi(tab[p->nb_numbers[A]]);
		if (is_number(tab[p->nb_numbers[A]]) \
			&& number <= INT_MAX && number >= INT_MIN)
			add_list(p, number);
		else
			trash_program(p, ERROR, "Out of limits number\n");
	}
	p->a->previous = last_list(p, p->a, A);
	return (0);
}
