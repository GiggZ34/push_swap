/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:01:18 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:47:42 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_number(long n, int fd, size_t *len)
{
	char	c;

	if (n > 9)
		ft_print_number(n / 10, fd, len);
	c = n % 10 + 48;
	*len += write(fd, &c, 1);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	long	nbr;

	nbr = n;
	len = 0;
	if (n < 0)
	{
		len += write(fd, "-", 1);
		nbr *= -1;
	}
	ft_print_number(nbr, fd, &len);
	return (len);
}
