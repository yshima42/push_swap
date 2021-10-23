/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:38:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/23 10:52:47 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error_exit(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	all_free_exit(stack, EXIT_FAILURE);
}

static char	*del_spaces(char const *str)
{
	char	*no_spaces_str;
	size_t	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	no_spaces_str = &((char *)str)[i];
	return (no_spaces_str);
}

static void	num_check(char *no_spaces_str, t_stack *stack, size_t i)
{
	if (no_spaces_str[i] < '0' || no_spaces_str[i] > '9')
		error_exit(stack);
	if (no_spaces_str[i] == '0' && no_spaces_str[i + 1] != '\0')
		error_exit(stack);
}

static void	int_max_check(int32_t sign, size_t result, t_stack *stack)
{
	if ((sign == -1 && result > 2147483648)
		|| (sign == 1 && result > 2147483647)
		|| (sign == -1 && result == 0))
		error_exit(stack);
}

int32_t	ps_atoi(const char *str, t_stack *stack)
{
	size_t	i;
	int32_t	sign;
	size_t	result;
	char	*no_spaces_str;

	i = 0;
	result = 0;
	no_spaces_str = del_spaces(str);
	sign = 1;
	if (no_spaces_str[i] == '-')
	{
		sign = -1;
		i++;
	}
	num_check(no_spaces_str, stack, i);
	while (no_spaces_str[i] >= '0' && no_spaces_str[i] <= '9')
	{
		result = result * 10 + (no_spaces_str[i] - '0');
		i++;
		int_max_check(sign, result, stack);
	}
	if (no_spaces_str[i])
		error_exit(stack);
	return ((int32_t)result * sign);
}
