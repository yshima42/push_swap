/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:56:57 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/21 22:12:28 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdbool.h>

# include "../libft/libft.h"

# define ARGS_LIMIT 15000
# define ERROR -1

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

typedef	struct s_pivots
{
	int	l_pivot;
	int	s_pivot;
} t_pivots;

typedef	struct s_dlst
{
	struct s_dlst *prev;
	int num;
	struct s_dlst *next;
} t_dlst;

typedef struct s_stack
{
	t_dlst	*a_head;
	t_dlst	*b_head;
	t_dlst	*ans;
} t_stack;

//dlst_utils.c
t_dlst	*dlst_new(int num);
int	dlst_size(t_dlst *head);
bool	dlst_add_back(t_dlst *head, t_dlst *new);
bool	dlst_del_front(t_dlst *head);
bool	dlst_del(t_dlst *elem);

//dlst_utils2.c
bool	dlst_del_back(t_dlst *head);
bool	dlst_add_front(t_dlst *head, t_dlst *new);
bool	dlst_swap(t_dlst *a, t_dlst *b);
bool	dlst_swap_front(t_dlst *head);
bool	dlst_rotate(t_dlst *head);

//dlst_utils3.c
bool	dlst_rev_rotate(t_dlst *head);
bool	dlst_push_top(t_dlst *from_head, t_dlst *to_head);

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

//output.c
void	ans_output(t_dlst *ans);

//args_check.c
void	args_check(int ac, char **av);

//init.c
t_stack	*init_stack(void);
void	init_count(t_count *count);

//reverse_stack.c
void	reverse_stack(t_stack *stack, t_count *count);

//find_pivots.c
void	find_pivots(t_dlst *dlst_head, int size, t_pivots *pivots);

void	ans_cut(t_dlst *ans);

//atob_qsort.c
bool	a_upto3(t_stack *stack, int size);
bool	is_sorted(t_dlst *head, int size);
bool	atob_qsort(t_stack *stack, int size);

bool	btoa_qsort(t_stack *stack, int size);

//main.c
void	algo_2(t_dlst *a_head, t_stack *stack);

//A_3_algo_utills.c
void	a_3_bac(t_stack *stack);
void	a_3_bca(t_stack *stack);
void	a_3_cba(t_stack *stack);
void	a_3_acb(t_stack *stack);
void	a_3_cab(t_stack *stack);

//B_3_algo_utils.c
void	b_3_bac(t_stack *stack);
void	b_3_bca(t_stack *stack);
void	b_3_acb(t_stack *stack);
void	b_3_cab(t_stack *stack);
void	b_3_abc(t_stack *stack);

//
void	algo_456(t_stack *stack);

void	algo_3(t_dlst *a_head, t_stack *stack);

void	algo_2(t_dlst *a_head, t_stack *stack);

//utils.c
void	av_to_dlst(t_dlst *head, int n_nums, char **av, t_stack *stack);

//all_free_exit.c
void	all_free_exit(t_stack *stack, int exit_status);

void	check_num_dup(t_dlst *head, t_stack *stack);

//bonus
bool	sa_exec(t_stack *stack);
bool	sb_exec(t_stack *stack);
bool	ss_exec(t_stack *stack);
bool	pa_exec(t_stack *stack);
bool	pb_exec(t_stack *stack);
bool	ra_exec(t_stack *stack);
bool	rb_exec(t_stack *stack);
bool	rr_exec(t_stack *stack);
bool	rra_exec(t_stack *stack);
bool	rrb_exec(t_stack *stack);
bool	rrr_exec(t_stack *stack);

void	ko_output_exit(t_stack *stack);

//後で消す
void	array_qsort(int *array, int start, int end);
int	*dlst_to_array(t_dlst *dlst_head, int size);
void	print_stacks(t_stack *stack);

#endif