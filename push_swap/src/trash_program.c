/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:18:12 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/02 11:22:35 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_list(t_push_swap *p, t_number **begin, int alpha)
{
	t_number	*current;
	t_number	*previous;
	int			i;

	current = *begin;
	i = -1;
	while (++i < p->nb_numbers[alpha])
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*begin = NULL;
}

int	trash_program(t_push_swap *p, int error_code, const char *msg)
{
	clear_list(p, &(p->a), A);
	clear_list(p, &(p->b), B);
	free(p->action);
	free(p->min);
	free(p->max);
	free(p->nb_numbers);
	if (error_code)
	{
		write(2, "ERROR\n", 6);
		write(2, msg, ft_strlen(msg));
	}
	exit(0);
	return (-1);
}
