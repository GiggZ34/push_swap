/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:18:12 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/05 19:34:53 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_list(t_push_swap *p, t_number **begin, int alpha)
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
	free(p->bigger_a);
	if (error_code)
		write(2, "\033[1;31mERROR\033[0m\n", 17);
	if (p->error_return)
		write(2, msg, ft_strlen(msg));
	exit(0);
	return (-1);
}

int	parsing_error(t_push_swap *p, int n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (trash_program(p, ERROR, "\033[33mOutside of limits\033[0m\n"));
	else
		return (trash_program(p, ERROR, "\033[33mBad character\033[0m\n"));
}
