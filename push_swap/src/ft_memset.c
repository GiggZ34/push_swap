/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:40:32 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 14:57:12 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*tab;

	tab = b;
	i = 0;
	while (i < len)
	{
		tab[i] = c;
		i++;
	}
	return (b);
}
