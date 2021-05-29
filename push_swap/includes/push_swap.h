/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:04:46 by grivalan          #+#    #+#             */
/*   Updated: 2021/05/29 18:40:44 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# define NBR_ACTION 4

typedef struct s_number
{
	struct s_number	*next;
	struct s_number	*previous;
	struct s_number	*last;
	int				n;
}t_number;

typedef struct s_push_swap
{
	int			*action;
	t_number	**max;
	t_number	**min;
	t_number	*first_one;
	t_number	*first_two;
	int			dir;
}t_push_swap;

typedef enum e_error_code
{
	SUCCESS,
	ERROR
}t_error_code;

typedef enum e_action
{
	R,
	RR,
	SR,
	SRR
}t_action;

int			numbers_to_list(t_push_swap *p, char **tab, int n);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
double		ft_abs(double n);
void		trash_program(t_push_swap *p, int error_code, const char *msg);
int			switch_number(t_push_swap *p, t_number **l1, t_number **l2, char c);
void		first_to_last(t_number **begin, const char *cmd);
void		last_to_first(t_number **begin, const char *cmd);
t_number	*before_last_list(t_number *lst);
t_number	*last_list(t_number *lst);
void		swap(t_number **begin, const char *cmd);
void		list_add_front(t_number **begin, t_number *new);
void		list_add_back(t_number **begin, t_number *new);
int			listsize(t_number *lst);
long		ft_atoi(const char *str);
int			generate_actions(t_push_swap *p);
void		process(t_push_swap *p);
int			treatment_list(t_push_swap *p);

void		print_lst(t_number *l1, t_number *l2);
void	asort_test(t_push_swap *p);

#endif
