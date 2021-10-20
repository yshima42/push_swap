/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:49:14 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 20:49:15 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ope_export(int ope)
{
	if (ope == PA)
		ft_putstr_fd("pa", 1);
	else if (ope == PB)
		ft_putstr_fd("pb", 1);
	else if (ope == SA)
		ft_putstr_fd("sa", 1);
	else if (ope == SB)
		ft_putstr_fd("sb", 1);
	else if (ope == SS)
		ft_putstr_fd("ss", 1);
	else if (ope == RA)
		ft_putstr_fd("ra", 1);
	else if (ope == RB)
		ft_putstr_fd("rb", 1);
	else if (ope == RR)
		ft_putstr_fd("rr", 1);
	else if (ope == RRA)
		ft_putstr_fd("rra", 1);
	else if (ope == RRB)
		ft_putstr_fd("rrb", 1);
	else if (ope == RRR)
		ft_putstr_fd("rrr", 1);
	else
		ft_putstr_fd("Error\n", 2);
}

void	ans_output(t_dlst *ans)
{
	t_dlst	*p;

	p = ans->next;
	while (p != ans)
	{
		ope_export(p->num);
		ft_putstr_fd("\n", 1);
		p = p->next;
	}
}
