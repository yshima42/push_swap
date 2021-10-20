/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:24:45 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 14:02:47 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	args_check(int n_nums, char **av)
{
	(void)av;
	if (n_nums < 1)
		exit (EXIT_FAILURE);
	
}
