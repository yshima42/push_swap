/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:35:30 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 13:35:45 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
