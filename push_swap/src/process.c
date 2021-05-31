/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:06:20 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/31 20:04:19 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_2_to_1(t_push_swap *p)
{
	t_number	*lst2;
	int			n;
	int			i;

	if (p->a)
	{
		n = p->a->n;
		lst2 = p->b;
		i = -1;
		while (++i < p->nb_numbers[B])
		{
			if (lst2->n > n)
				return (0);
			lst2 = lst2->next;
		}
	}
	return (1);
}

static int	check_asort(t_push_swap *p, t_number *lst, int num_lst)
{
	int	tmp;
	int	i;

	if (lst)
	{
		tmp = lst->n;
		lst = lst->next;
		i = -1;
		while (++i < p->nb_numbers[num_lst])
		{
			if (tmp < lst->n)
				return (0);
			tmp = lst->n;
			lst = lst->next;
		}
	}
	return (1);
}

static int	check_sort(t_push_swap *p, t_number *lst, int num_lst)
{
	int	tmp;
	int	i;

	if (lst)
	{
		tmp = lst->n;
		lst = lst->next;
		i = -1;
		while (++i < p->nb_numbers[num_lst])
		{
			if (tmp > lst->n)
				return (0);
			tmp = lst->n;
			lst = lst->next;
		}
	}
	return (1);
}

// modifier cette fonction une fois le sorte convenablement installé pour optimiser les 3 plus gros nombres de p->a

static int	check_list(t_push_swap *p)
{
	if (!p->nb_numbers[A])
		return (check_sort(p, p->a, A));
	else if (!p->nb_numbers[B])
		return (asort_list_b(p));
	return (0);
}

void	process(t_push_swap *p)
{
	int	i;

	i = -1;
	while (!check_list(p))
	{
		if (check_sort(p, p->a, A) && check_asort(p, p->b, B) \
			&& check_2_to_1(p))
			while (p->nb_numbers[B])
				switch_number(p, &p->b, &p->a, 'a');
		else
			treatment_list(p);
	print_lst(p);
	}
	trash_program(p, ERROR, "exit\n");
}
