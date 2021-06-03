/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:29:16 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/03 11:37:04 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' && !ft_isdigit(str[i + 1])) \
		|| (str[i] != '-' && !ft_isdigit(str[i])))
		return (0);
	while (str[++i] && !is_whitespace(str[i]))
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
	int		i;

	i = -1;
	while (++i < n)
	{
		while (*(tab[i]))
		{
			while (*(tab[i]) && is_whitespace(*(tab[i])))
				tab[i]++;
			number = ft_atoi(tab[i]);
			if (*tab[i] && is_number(tab[i]) \
				&& number <= INT_MAX && number >= INT_MIN)
			{
				add_list(p, number);
				p->nb_numbers[A]++;
				while (*(tab[i]) && ft_isdigit(*(tab[i])))
					tab[i]++;
			}
			else if (*tab[i])
				trash_program(p, ERROR, "Out of limits integer\n");
		}
	}
	p->a->previous = last_list(p, p->a, A);
	return (0);
}
