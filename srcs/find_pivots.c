/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:30:48 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 14:36:53 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	array_qsort(int32_t *array, int32_t start, int32_t end)
{
	int32_t	tmp;
	int32_t	pivot;
	int32_t	i;
	int32_t	j;

	if (start < end)
	{
		pivot = array[(start + end) / 2];
		i = start - 1;
		j = end + 1;
		while (1)
		{
			while (array[++i] < pivot)
				;
			while (array[--j] > pivot)
				;
			if (i >= j)
				break ;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		array_qsort(array, start, i - 1);
		array_qsort(array, j + 1, end);
	}
}

int32_t	*dlst_to_array(t_dlst *dlst_head, int32_t size)
{
	int32_t	*array;
	t_dlst	*p;
	int32_t	i;

	p = dlst_head->next;
	array = (int32_t *)malloc(sizeof(int32_t) * size);
	if (array == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (EXIT_FAILURE);
	}
	i = -1;
	while (++i < size)
	{
		array[i] = p->num;
		p = p->next;
	}
	return (array);
}

void	find_pivots(t_dlst *dlst_head, int32_t size, t_pivots *pivots)
{
	int32_t	*array;

	array = dlst_to_array(dlst_head, size);
	array_qsort(array, 0, size - 1);
	pivots->s_pivot = array[size / 3];
	pivots->l_pivot = array[size * 2 / 3];
	free(array);
}
