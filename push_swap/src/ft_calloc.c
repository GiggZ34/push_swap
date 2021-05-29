/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:37:25 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 15:51:50 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;

	tab = malloc(size * count);
	if (!tab)
		return (0);
	i = 0;
	while (i < count * size)
		tab[i++] = 0;
	return (tab);
}
