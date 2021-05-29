/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:18:12 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 15:44:40 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_list(t_number **begin)
{
	t_number	*current;
	t_number	*previous;

	current = *begin;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*begin = NULL;
}

void	trash_program(t_push_swap *p, int error_code, const char *msg)
{
	clear_list(&(p->first_one));
	clear_list(&(p->first_two));
	free(p->action);
	free(p->min);
	free(p->max);
	if (error_code)
	{
		write(2, "ERROR\n", 6);
		write(2, msg, ft_strlen(msg));
	}
	exit(0);
}
