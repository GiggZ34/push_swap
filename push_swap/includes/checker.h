/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:35:39 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/06 14:57:08 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H
# include "push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_fd
{
	int			fd;
	char		*buff;
	int			start;
	int			end;
	struct s_fd	*next;
}t_fd;

char	*ft_realloc(char *str, int size);
int		ft_strpos(const char *s, char c);
char	*ft_substr(char const *s, int start, int len);
int		get_next_line(int fd, char **line);
int		check(t_push_swap *p);
int		exit_program(t_push_swap *p, int error_code, const char *msg);
int		treatment_checker(t_push_swap *p, char *line, int len);
#endif
