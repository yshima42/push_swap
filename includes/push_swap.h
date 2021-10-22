/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:56:57 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 18:34:37 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdbool.h>

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

typedef struct s_count
{
	int32_t	n_ra;
	int32_t	n_rb;
	int32_t	n_pa;
	int32_t	n_pb;
}	t_count;

typedef struct s_pivots
{
	int32_t	l_pivot;
	int32_t	s_pivot;
}	t_pivots;

typedef struct s_dlst
{
	struct s_dlst	*prev;
	int32_t			num;
	struct s_dlst	*next;
}	t_dlst;

typedef struct s_stack
{
	t_dlst	*a_head;
	t_dlst	*b_head;
	t_dlst	*ans;
}	t_stack;

//a_3_algo_utills.c
void	a_3_bac(t_stack *stack);
void	a_3_bca(t_stack *stack);
void	a_3_cba(t_stack *stack);
void	a_3_acb(t_stack *stack);
void	a_3_cab(t_stack *stack);

//algo_2.c
void	algo_2(t_dlst *a_head, t_stack *stack);

//algo_3.c
void	algo_3(t_dlst *a_head, t_stack *stack);

//algo_456.c
void	algo_456(t_stack *stack);

//all_free_exit.c
void	all_free_exit(t_stack *stack, int32_t exit_status);

//ans_cut.c
void	ans_cut(t_dlst *ans);

//args_check.c
void	args_check(int32_t ac, char **av);

//atob_qsort.c
bool	a_upto3(t_stack *stack, int32_t size);
bool	is_sorted(t_dlst *head, int32_t size);
bool	atob_qsort(t_stack *stack, int32_t size);

//av_to_dlst.c
void	av_to_dlst(t_dlst *head, int32_t n_nums, char **av, t_stack *stack);

//b_3_algo_utils.c
void	b_3_bac(t_stack *stack);
void	b_3_bca(t_stack *stack);
void	b_3_acb(t_stack *stack);
void	b_3_cab(t_stack *stack);
void	b_3_abc(t_stack *stack);

//btoa_qsort.c
bool	btoa_qsort(t_stack *stack, int32_t size);

//check_num_dup.c
void	check_num_dup(t_dlst *head, t_stack *stack);

//dlst_utils1.c
t_dlst	*dlst_new(int32_t num);
int32_t	dlst_size(t_dlst *head);
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

//find_pivots.c
void	find_pivots(t_dlst *dlst_head, int32_t size, t_pivots *pivots);
void	array_qsort(int32_t *array, int32_t start, int32_t end);
int32_t	*dlst_to_array(t_dlst *dlst_head, int32_t size);

//init.c
t_stack	*init_stack(void);
void	init_count(t_count *count);

//operations1.c
bool	sa(t_stack *stack);
bool	sb(t_stack *stack);
bool	ss(t_stack *stack);
bool	pa(t_stack *stack);
bool	pb(t_stack *stack);

//operations2.c
bool	ra(t_stack *stack);
bool	rb(t_stack *stack);
bool	rr(t_stack *stack);

//operations3.c
bool	rra(t_stack *stack);
bool	rrb(t_stack *stack);
bool	rrr(t_stack *stack);

//output.c
void	ans_output(t_dlst *ans);

//ps_atoi.c
int32_t	ps_atoi(const char *str, t_stack *stack);

//reverse_stack.c
void	reverse_stack(t_stack *stack, t_count *count);

//bonus
//operations1.c
bool	sa_exec(t_stack *stack);
bool	sb_exec(t_stack *stack);
bool	ss_exec(t_stack *stack);
bool	pa_exec(t_stack *stack);
bool	pb_exec(t_stack *stack);

//operations2.c
bool	ra_exec(t_stack *stack);
bool	rb_exec(t_stack *stack);
bool	rr_exec(t_stack *stack);

//operations3.c
bool	rra_exec(t_stack *stack);
bool	rrb_exec(t_stack *stack);
bool	rrr_exec(t_stack *stack);

//output_bonus.c
void	ok_output_exit(t_stack *stack);
void	ko_output_exit(t_stack *stack);

//ans_check_bonus.c
bool	ans_check(t_stack *stack, int32_t n_nums);

//ps_gnl_bonus.c
char	*ps_gnl(int fd, t_gnl *t_buff);

//ps_gnl_utils_bonus.c
t_gnl	*ps_gnlnew(int fd, char *c);
char	*ps_strndup(const char *src, size_t n);

#endif