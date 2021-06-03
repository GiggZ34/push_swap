/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:35:13 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/03 11:37:34 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_asort(t_number *lst)
{
	t_number	*end;
	int			tmp;
	int			i;

	end = lst;
	if (lst)
	{
		tmp = lst->n;
		lst = lst->next;
		i = -1;
		while (lst != end)
		{
			if (tmp < lst->n)
				return (0);
			tmp = lst->n;
			lst = lst->next;
		}
	}
	return (1);
}

int	check_sort(t_push_swap *p, t_number **lst)
{
	t_number	*num;
	int			tmp;
	int			end;
	int			bigger;

	num = *lst;
	if (lst && p->nb_numbers[A] > 1)
	{
		bigger = search_number(num, p->bigger_a[0]->n);
		while (--bigger > -1)
			num = num->next;
		end = num->n;
		num = num->next;
		tmp = num->n;
		p->min[0] = num;
		while (num->n < end)
		{
			if (tmp > num->n)
				return (-1);
			tmp = num->n;
			num = num->next;
		}
	}
	return (search_number(*lst, p->bigger_a[0]->n) + 1);
}

int	turn_list(t_push_swap *p, t_number **lst, char alpha, int end)
{
	int		num;
	char	cmd[5];
	int		id;

	id = search_number(*lst, end);
	num = alpha - 'a';
	ft_memset(cmd, 0, sizeof(char) * 5);
	cmd[0] = 'r';
	while (*lst && (*lst)->n != end)
	{
		if (id <= p->nb_numbers[num] - id)
		{
			cmd[1] = alpha;
			cmd[2] = '\n';
			first_to_last(lst, cmd);
		}
		else
		{
			cmd[1] = 'r';
			cmd[2] = alpha;
			cmd[3] = '\n';
			last_to_first(lst, cmd);
		}
	}
	return (check_sort(p, lst) + 1 == p->nb_numbers[A]);
}

int	asort_list_b(t_push_swap *p)
{
	t_number	*l;
	int			id;

	l = p->b;
	id = search_number(p->b, p->max[1]->n);
	while (l->n < p->max[1]->n)
	{
		id++;
		l = l->next;
	}
	while (p->b->n != p->max[1]->n)
	{
		if (id <= p->nb_numbers[B] - id)
			first_to_last(&p->b, "rb\n");
		else
			last_to_first(&p->b, "rrb\n");
	}
	return (1);
}
