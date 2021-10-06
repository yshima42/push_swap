/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/06 18:07:26 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef	struct s_dlst
{
	struct s_dlst *prev;
	int num;
	struct s_dlst *next;
} t_dlst;


/* 

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!f || !lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

*/

/* int add1(int a)
{
	a = a + 1;
	return(a);
}

void	dlst_iter(t_dlst *dlst, int f(int))
{
	if (!dlst || !f)
		return ;
	dlst = dlst->next;
	while (dlst->num)
	{
		f(dlst->num);
		dlst = dlst->next;
	}
} */

/* void	dlst_clear(t_dlst *head)
{
	t_dlst	*elem;

	elem = head;
	while (elem->next)
	{
		elem = elem->next;
		free(elem);
		printf("a");
		//elem->prev = NULL;
	}
	free(head);
	//head = NULL;
} */

t_dlst	*dlst_new(int num)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if (!elem)
		return (NULL);
	elem->prev = elem->next = elem;
	elem->num = num;
	return (elem);
}

int	dlst_size(t_dlst *head)
{
	size_t	size;
	t_dlst	*p;

	if (!head)
		return (0);
	size = 0;
	p = head->next;
	while (p != head)
	{
		p = p->next;
		size++;
	}
	return (size);
} 

void	dlst_add_back(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return ;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}


void	dlst_del_front(t_dlst *head)
{
	t_dlst *elem;
	
	if (!head)
		return ;
	elem = head->next;
	elem->next->prev = head;
	head->next = elem->next;	
	free(elem);
}

void	dlst_del_back(t_dlst *head)
{
	t_dlst *elem;
	
	if (!head)
		return ;
	elem = head->prev;
	elem->prev->next = head;
	head->prev = elem->prev;
	free(elem);
}

void	dlst_add_front(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return ;
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;
}

void	dlst_swap_front(t_dlst *head)
{
	t_dlst	*elem;
	
	if (!head)
		return ;
	elem = head->next->next;
	head->next->next = elem->next;
	head->next->prev = elem;
	elem->prev = head;
	elem->next = head->next;
	head->next = elem;
}

void	dlst_rotate(t_dlst *head)
{
	t_dlst	*front;
	t_dlst	*back;
	
	if (!head)
		return ;
	front = head->prev;
	back = head->next;
	back->next->prev = head;
	head->next = back->next;
	head->prev = back;
	back->prev = front;
	back->next = head;
	front->next = back;
}

void	dlst_rev_rotate(t_dlst *head)
{
	t_dlst	*front;
	t_dlst	*back;
	
	if (!head)
		return ;
	front = head->next;
	back = head->prev;
	back->prev->next = head;
	head->prev = back->prev;
	head->next = back;
	back->next = front;
	back->prev = head;
	front->prev = back;
}

void	dlst_push(t_dlst *to, t_dlst *from)
{
	dlst_add_front(to, dlst_new(from->next->num));
	dlst_del_front(from);
}

t_dlst	*dlst_init(void)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if(!elem)
	{
		ft_putstr_fd("malloc error", 2);
		exit(1);
	}
	//後で消す
	elem->num = 100000;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}

void	args_check(int ac, char **av)
{
	(void)av;
	if (ac < 2)
		exit (EXIT_FAILURE);
}

void	print_stacks(t_dlst *a_head, t_dlst *b_head)
{
	t_dlst *p;
	
	p = a_head->next;
	while(p != a_head)
	{
		printf("A: %d\n",p->num);
		p = p->next;
	}
	printf("\n");
	p = b_head->next;
	while(p != b_head)
	{
		printf("B: %d\n",p->num);
		p = p->next;
	}
}

void	av_to_a(t_dlst *a_head, char **av)
{
	size_t	i;
	
	i = 0;
	while (av[++i])
	{
		dlst_add_back(a_head, dlst_new(ft_atoi(av[i])));
	}
}

void	sa(t_dlst *a_head)
{
	dlst_swap_front(a_head);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_dlst *b_head)
{
	dlst_swap_front(b_head);
	ft_putstr_fd("sb\n", 1);
}

void	ra(t_dlst *a_head)
{
	dlst_rotate(a_head);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_dlst *b_head)
{
	dlst_rotate(b_head);
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_dlst *a_head)
{
	dlst_rev_rotate(a_head);
	ft_putstr_fd("rra\n", 1);
}

void	algo_2(t_dlst *a_head)
{
	if (a_head->next->num > a_head->prev->num)
		sa(a_head);
	else
		ft_putstr_fd("no need to change\n", 1);
}

void	algo_3(t_dlst *a_head)
{
	if (a_head->next->num > a_head->next->next->num
		&& a_head->prev->num > a_head->next->num)
		sa(a_head);
	else if (a_head->next->num > a_head->next->next->num
		&& a_head->prev->num > a_head->next->next->num)
		ra(a_head);
	else if (a_head->next->num > a_head->next->next->num
		&& a_head->prev->num < a_head->next->next->num)
	{
		printf("%d\n", a_head->next->next->next->next->num);
		sa(a_head);
		printf("%d\n", a_head->next->next->next->next->num);
		rra(a_head);
		printf("%d\n", a_head->next->next->next->next->num);
	}
	else
		exit (0);
}

int	main(int ac, char **av)
{
	t_dlst *a_head;
	t_dlst *b_head;
	int	n_num;

	args_check(ac, av);
	a_head = dlst_init();
	b_head = dlst_init();
	av_to_a(a_head, av);
	n_num = ac--;
	if (ac == 1)
		ft_putstr_fd("no need to change", 1);
	else if (ac == 2)
		algo_2(a_head);
	else if (ac == 3)
		algo_3(a_head);
	/* else if (ac <= 6)
		algo_u6(a_head, b_head, n_num); */
	else
		return (0);
	print_stacks(a_head, b_head);
	return (0);
}
