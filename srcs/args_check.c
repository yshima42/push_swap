/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:24:45 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 23:38:49 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	args_check(int32_t n_nums)
{
	if (n_nums < 1)
	{
		exit(EXIT_SUCCESS);
	}
	if (ARGS_LIMIT < n_nums)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
