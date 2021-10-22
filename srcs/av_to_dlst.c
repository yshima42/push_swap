/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_to_dlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:27:00 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 14:26:13 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	av_to_dlst(t_dlst *head, int32_t n_nums, char **av, t_stack *stack)
{
	int32_t	i;
	int32_t	num;

	i = 0;
	while (++i <= n_nums)
	{
		num = ps_atoi(av[i], stack);
		dlst_add_back(head, dlst_new(num));
	}
}
