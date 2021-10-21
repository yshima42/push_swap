/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:05:59 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/21 22:30:32 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack)
{
	t_dlst *p;
	
	p = stack->a_head->next;
	while(p != stack->a_head)
	{
		printf("A: %d\n",p->num);
		p = p->next;
	}
	printf("\n");
	p = stack->b_head->next;
	while(p != stack->b_head)
	{
		printf("B: %d\n",p->num);
		p = p->next;
	}
}

static int ope_to_int(char *ans)
{
	if (!(ft_strncmp("pa", ans, 3)))
		return (PA);
	else if (!(ft_strncmp("pb", ans, 3)))
		return (PB);
	else if (!(ft_strncmp("sa", ans, 3)))
		return (SA);
	else if (!(ft_strncmp("sb", ans, 3)))
		return (SB);
	else if (!(ft_strncmp("ss", ans, 3)))
		return (SS);
	else if (!(ft_strncmp("ra", ans, 3)))
		return (RA);
	else if (!(ft_strncmp("rb", ans, 3)))
		return (RB);
	else if (!(ft_strncmp("rr", ans, 3)))
		return (RR);
	else if (!(ft_strncmp("rra", ans, 4)))
		return (RRA);
	else if (!(ft_strncmp("rrb", ans, 4)))
		return (RRB);
	else if (!(ft_strncmp("rrr", ans, 4)))
		return (RRR);
	else
		return(ERROR);
}

void	operations_exec(t_stack *stack)
{
	t_dlst	*p;

	p = stack->ans->next;
	while (p != stack->ans)
	{
		if (p->num == PA)
			pa_exec(stack);
		else if (p->num == PB)
			pb_exec(stack);
		else if (p->num == SA)
			sa_exec(stack);
		else if (p->num == SB)
			sb_exec(stack);
		else if (p->num == SS)
			ss_exec(stack);
		else if (p->num == RA)
			ra_exec(stack);
		else if (p->num == RB)
			rb_exec(stack);
		else if (p->num == RR)
			rr_exec(stack);
		else if (p->num == RRA)
			rra_exec(stack);
		else if (p->num == RRB)
			rrb_exec(stack);
		else if (p->num == RRR)
			rrr_exec(stack);
		p = p->next;
	}
}

bool	ans_check(t_stack *stack, int n_nums)
{
	operations_exec(stack);
	if (is_sorted(stack->a_head, n_nums))
		return (true);
	else
		return (false);
}

void	ok_output_exit(t_stack *stack)
{
	ft_putstr_fd("OK\n", 1);
	all_free_exit(stack, EXIT_SUCCESS);
}

void	ko_output_exit(t_stack *stack)
{
	ft_putstr_fd("KO\n", 1);
	all_free_exit(stack, EXIT_SUCCESS);
}

void	ans_get_dlst(t_stack *stack)
{
	char	*ans_str;
	int	ans_int;

	while (1)
	{
		ans_str = get_next_line(0);
		if (!ans_str)
			break ;
		ans_int = ope_to_int(ans_str);
		if (ans_int == ERROR)
		{
			ft_putstr_fd("Error\n", 2);
			all_free_exit(stack, EXIT_FAILURE);
		}
		dlst_add_back(stack->ans, dlst_new(ans_int));
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		n_nums;

	n_nums = ac - 1;
	args_check(n_nums, av);
	stack = init_stack();
	av_to_dlst(stack->a_head, n_nums, av, stack);
	check_num_dup(stack->a_head, stack);
	ans_get_dlst(stack);
	if (ans_check(stack, n_nums))
		ok_output_exit(stack);
	else
		ko_output_exit(stack);
	return(0);
}
