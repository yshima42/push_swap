/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:56:57 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/15 18:56:37 by yshimazu         ###   ########.fr       */
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


#endif