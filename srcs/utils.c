/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:27:00 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:27:42 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	av_to_dlst(t_stack *stack, int ac, char **av)
{
	int	i;
	int	num;

	i = 0;
	while (++i < ac)
	{
		num = ft_atoi(av[i]);//+-の処理
		dlst_add_back(stack->a_head, dlst_new(num));
	}
}
