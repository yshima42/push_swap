/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:27:00 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 22:57:01 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	error_exit(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	all_free_exit(stack, EXIT_FAILURE);
}

void	c_is_num_check(char c, t_stack *stack)
{
	if (c < '0' || c > '9')
		error_exit(stack);
}

void	after_check(char c, t_stack *stack)
{
	if (c)
		error_exit(stack);
}

int	ps_atoi(const char *str, t_stack *stack)
{
	size_t	i;
	int		sign;
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
	c_is_num_check(no_spaces_str[i], stack);
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
	return ((int)result * sign);
}

void	av_to_dlst(t_dlst *head, int n_nums, char **av, t_stack *stack)
{
	int	i;
	int	num;

	i = 0;
	while (++i <= n_nums)
	{
		num = ps_atoi(av[i], stack);
		dlst_add_back(head, dlst_new(num));
	}
}
