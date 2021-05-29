/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:29:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/28 17:55:56 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(t_push_swap *p, t_number *lst, t_number *check)
{
	while (lst)
	{
		if (lst->n == check->n)
		{
			free(check);
			trash_program(p, ERROR, "Number duplicate\n");
		}
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
	check_duplicate(p, p->first_one, number);
	list_add_back(&(p->first_one), number);
}

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

int	numbers_to_list(t_push_swap *p, char **tab, int n)
{
	int		i;
	long	number;

	i = -1;
	while (++i < n)
	{
		number = ft_atoi(tab[i]);
		if (is_number(tab[i]) && number <= INT_MAX && number >= INT_MIN)
			add_list(p, number);
		else
			trash_program(p, ERROR, "Out of limits number\n");
	}
	return (0);
}
