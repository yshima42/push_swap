/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:05:59 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 19:01:07 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int32_t	ope_to_int(char *ans)
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
		return (ERROR);
}

static void	ans_get_dlst(t_stack *stack)
{
	char	*ans_str;
	int32_t	ans_int;

	while (1)
	{
		ans_str = ps_gnl(0);
		if (!ans_str)
			break ;
		ans_int = ope_to_int(ans_str);
		if (ans_int == ERROR)
		{
			ft_putstr_fd("Error\n", 2);
			all_free_exit(stack, EXIT_FAILURE);
		}
		free(ans_str);
		dlst_add_back(stack->ans, dlst_new(ans_int));
	}
}

int	main(int32_t ac, char **av)
{
	t_stack	*stack;
	int32_t	n_nums;

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
	return (0);
}
