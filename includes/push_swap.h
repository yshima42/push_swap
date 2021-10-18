/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:56:57 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/18 17:32:17 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdbool.h>

# include "../libft/libft.h"

void	array_qsort(int *array, int start, int end);

typedef enum e_cmd
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_cmd;

typedef	struct s_count
{
	int	n_ra;
	int	n_rb;
	int	n_pa;
	int	n_pb;
} t_count;


typedef	struct s_dlst
{
	struct s_dlst *prev;
	int order;
	int num;
	struct s_dlst *next;
} t_dlst;

typedef struct s_stack
{
	t_dlst	*a_head;
	t_dlst	*b_head;
	t_dlst	*ans;
	int	n_ABqsort;
	int	n_BAqsort;
} t_stack;

//dlst_utils.c
t_dlst	*dlst_new(int num);
int	dlst_size(t_dlst *head);
void	dlst_add_back(t_dlst *head, t_dlst *new);
void	dlst_del_front(t_dlst *head);
void	dlst_del(t_dlst *elem);

//dlst_utils2.c
void	dlst_del_back(t_dlst *head);
void	dlst_add_front(t_dlst *head, t_dlst *new);
void	dlst_swap(t_dlst *a, t_dlst *b);
void	dlst_swap_front(t_dlst *head);
void	dlst_rotate(t_dlst *head);

//dlst_utils3.c
void	dlst_rev_rotate(t_dlst *head);
void	dlst_push_top(t_dlst *from_head, t_dlst *to_head);
t_dlst	*dlst_init(void);

//operations.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

//operations2.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

//operations3.c
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif