/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/07 10:28:42 by yshimazu         ###   ########.fr       */
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

void	dlst_del(t_dlst *elem)
{
	t_dlst	*front;
	t_dlst	*back;
	
	if (!elem)
		return ;
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;	
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
	elem->next->prev = elem->prev;
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

void	dlst_push(t_dlst *from, t_dlst *to)
{
	dlst_add_front(to, dlst_new(from->num));
	dlst_del(from);
}

void	dlst_push_top(t_dlst *from_head, t_dlst *to_head)
{
	t_dlst *elem;
	
	elem = from_head->next;
	dlst_add_front(to_head, dlst_new(elem->num));
	dlst_del(elem);
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
	//elem->num = 100000;
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

void	ss(t_dlst *a_head, t_dlst *b_head)
{
	dlst_swap_front(a_head);
	dlst_swap_front(b_head);
	ft_putstr_fd("ss\n", 1);
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

void	rr(t_dlst *a_head, t_dlst *b_head)
{
	dlst_rotate(a_head);
	dlst_rotate(b_head);
	ft_putstr_fd("rr\n", 1);	
}

void	rra(t_dlst *a_head)
{
	dlst_rev_rotate(a_head);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_dlst *b_head)
{
	dlst_rev_rotate(b_head);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_dlst *a_head, t_dlst *b_head)
{
	dlst_rev_rotate(a_head);
	dlst_rev_rotate(b_head);
	ft_putstr_fd("rrr\n", 1);
}

void	pa(t_dlst *a_head, t_dlst *b_head)
{
	dlst_push_top(b_head, a_head);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_dlst *a_head, t_dlst *b_head)
{
	dlst_push_top(a_head, b_head);
	ft_putstr_fd("pb\n", 1);
}

bool	is_closer_front(t_dlst *a_head, t_dlst *p_s)
{
	int	dis_front;
	int	dis_back;
	t_dlst	*p;

	dis_front = 0;
	dis_back = 0;
	p = a_head;
	while(p != p_s)
	{
		p = p->next;
		dis_front++;
	}
	p = a_head;
	while(p != p_s)
	{
		p = p->prev;
		dis_back++;
	}
	if (dis_front <= dis_back)
		return (true);
	else
		return (false);
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
	int a;
	int b;
	int c;
	
	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->prev->num;
	if (b < a && a < c)
		sa(a_head);
	else if (b < c && c < a)
		ra(a_head);
	else if (c < b && b < a)
	{
		sa(a_head);
		rra(a_head);
	}
	else if (a < c && c < b)
	{
		sa(a_head);
		ra(a_head);
	}
	else if (c < a && a < b)
		rra(a_head);
	else
		ft_putstr_fd("same numbers or no need to change\n", 2);//エラーハンドリングする
}

void	pushb_till_3(t_dlst	*a_head, t_dlst	*b_head)
{
	t_dlst	*p;
	t_dlst	*p_s;
	int		size;

	size = dlst_size(a_head);
	while(size > 3)
	{
		p = a_head->next;
		p_s = a_head->next;
		while(p != a_head)
		{
			if (p->num < p_s->num)
				p_s = p;
			p = p->next;
		}
		if (is_closer_front(a_head, p_s))
		{
			while(a_head->next != p_s)
				ra(a_head);
		}
		else
		{
			while(a_head->next != p_s)
				rra(a_head);
		}
		pb(a_head, b_head);
		size = dlst_size(a_head);
	}
}

void	pusha_till_done(t_dlst *a_head, t_dlst *b_head)
{
	while(b_head->next != b_head)
		pa(a_head, b_head);
}

void	algo_u6(t_dlst *a_head, t_dlst *b_head)
{
	pushb_till_3(a_head, b_head);
	algo_3(a_head);
	pusha_till_done(a_head, b_head);
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
	else if (ac <= 6)
		algo_u6(a_head, b_head);
	else
		return (0);
	print_stacks(a_head, b_head);
	return (0);
}
