/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_gnl_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:30:10 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 18:13:40 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_gnl	*ps_gnlnew(int fd, char *c)
{
	t_gnl	*elem;

	elem = (t_gnl *)malloc(sizeof(t_gnl));
	if (!elem)
		return (NULL);
	elem->fd = fd;
	elem->memo = ft_strndup(c, ft_strlen(c));
	elem->next = NULL;
	return (elem);
}

char	*ps_strndup(const char *src, size_t n)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (src[len])
		len++;
	ptr = (char *)malloc(n + 1);
	if (ptr == 0)
		return (0);
	len = 0;
	while (len < n)
	{
		ptr[len] = src[len];
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}
