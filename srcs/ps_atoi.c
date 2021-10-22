/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:38:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 23:25:57 by yshimazu         ###   ########.fr       */
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

static void	c_is_num_check(char c, t_stack *stack)
{
	if (c < '0' || c > '9')
		error_exit(stack);
}

static void	after_check(char c, t_stack *stack)
{
	if (c)
		error_exit(stack);
}

int32_t	ps_atoi(const char *str, t_stack *stack)
{
	size_t	i;
	int32_t	sign;
	size_t	result;
	char	*no_spaces_str;

	i = -1;
	result = 0;
	no_spaces_str = del_spaces(str);
	sign = 1;
	if (no_spaces_str[++i] == '-')
		sign = -1;
	c_is_num_check(no_spaces_str[i], stack);
	if (no_spaces_str[i] == '0' && no_spaces_str[i + 1] != '\0')
		error_exit(stack);
	while (no_spaces_str[i] >= '0' && no_spaces_str[i] <= '9')
	{
		result = result * 10 + (no_spaces_str[i] - '0');
		i++;
		if ((sign == -1 && result > 2147483648)
			|| (sign == 1 && result > 2147483647)
			|| (sign == -1 && result == 0))
			error_exit(stack);
	}
	after_check(no_spaces_str[i], stack);
	return ((int32_t)result * sign);
}
