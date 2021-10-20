/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:27:00 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 15:19:15 by yshimazu         ###   ########.fr       */
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

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	c_is_num_check(char c)
{
	if (c < '0' || c > '9')
		error_exit();
}

int	ps_atoi(const char *str)
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
	c_is_num_check(no_spaces_str[i]);
	while (no_spaces_str[i] >= '0' && no_spaces_str[i] <= '9')
	{
		result = result * 10 + (no_spaces_str[i] - '0');
		i++;
		if ((sign == -1 && result > 2147483648)
			|| (sign == 1 && result > 2147483647))
			error_exit();
	}
	return ((int)result * sign);
}

void	av_to_dlst(t_dlst *head, int n_nums, char **av)
{
	int	i;
	int	num;

	i = 0;
	while (++i <= n_nums)
	{
		num = ps_atoi(av[i]);
		if (INT32_MAX < num || num < INT32_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		dlst_add_back(head, dlst_new(num));
	}
}
