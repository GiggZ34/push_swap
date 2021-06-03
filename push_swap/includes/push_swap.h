/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:04:46 by grivalan          #+#    #+#             */
/*   Updated: 2021/06/03 11:36:10 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# define NB_LST 2

typedef struct s_number
{
	struct s_number	*next;
	struct s_number	*previous;
	int				n;
}t_number;

typedef struct s_push_swap
{
	int			*action;
	t_number	**max;
	t_number	**min;
	t_number	**bigger_a;
	t_number	*a;
	t_number	*b;
	int			*nb_numbers;
	int			error_return;
}t_push_swap;

typedef enum e_error_code
{
	SUCCESS,
	ERROR
}t_error_code;

typedef enum e_actions_tab
{
	TOTAL,
	DIR_A,
	NB_A,
	DIR_B,
	NB_B
}t_actions_tab;

typedef enum e_action
{
	R,
	RR,
	SR,
	SRR
}t_action;

typedef enum e_lst
{
	A,
	B
}t_lst;

int			numbers_to_list(t_push_swap *p, char **tab, int n);
void		add_bigger_number(t_push_swap *p, t_number *n);
int			is_bigger(t_push_swap *p, t_number *n);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_abs(int n);
int			trash_program(t_push_swap *p, int error_code, const char *msg);
int			switch_number(t_push_swap *p, t_number **s, t_number **d, char *c);
void		first_to_last(t_number **begin, const char *cmd);
void		last_to_first(t_number **begin, const char *cmd);
int			search_number(t_number *list, int n);
t_number	*last_list(t_push_swap *p, t_number *lst, int num_lst);
void		swap(t_number **begin, const char *cmd);
void		list_add_front(t_number **b, t_number *new);
void		list_add_back(t_push_swap *p, t_number **b, t_number *new, int lst);
long		ft_atoi(const char *str);
int			search_actions(t_push_swap *p);
void		process(t_push_swap *p);
int			treatment_list(t_push_swap *p);
int			asort_list_b(t_push_swap *p);
int			check_asort(t_number *lst);
int			check_sort(t_push_swap *p, t_number **lst);
int			turn_list(t_push_swap *p, t_number **lst, char alpha, int end);

#endif
