/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/07 16:54:17 by yshimazu         ###   ########.fr       */
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
	
	if (!elem || elem->next == elem)
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

int	check_distance(t_dlst *min, t_dlst *max)
{
	int dis_front;

	dis_front = 0;
	while(min != max)
	{
		min = min->next;
		dis_front++;
	}
	return(dis_front);
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

void	moveb_to_aback_tilldone(t_dlst *a_head, t_dlst *b_head)
{
	while(b_head->next != b_head)
	{
		pa(a_head, b_head);
		ra(a_head);
	}
}

void	pusha_3_times(t_dlst *a_head, t_dlst *b_head)
{
	int i;

	i = -1;
	while(++i < 3)
		pa(a_head, b_head);
}

void	algo_u6(t_dlst *a_head, t_dlst *b_head)
{
	pushb_till_3(a_head, b_head);
	algo_3(a_head);
	pusha_3_times(a_head, b_head);
}

t_dlst	*med3(t_dlst *min, t_dlst *max, t_dlst *p)
{
	int	a;
	int	b;
	int	c;

	a = min->num;
	b = max->num;
	c = p->num;
	if (a < b)
		if (b < c)
			return (max);
		else if (a < c)
			return (p);
		else
			return (min);
	else
		if (a < c)
			return (min);
		else if (b < c)
			return (p);
		else
			return (max);
}

t_dlst	*find_pivot(t_dlst *min, t_dlst *max)
{
	int dis;
	int	i;
	t_dlst	*p;
	
	i = 0;
	dis = check_distance(min, max);
	printf("dis: %d\n",dis);
	/* if (dis < 2)
		return (NULL); */
	dis /= 2;
	p = min;
	while(i < dis)
	{
		p = p->next;
		i++;
	}
	return (med3 (min, max, p));
}

void	arrange(t_dlst *a_head, t_dlst *b_head, t_dlst *min, t_dlst *max, t_dlst *pivot)
{
	t_dlst	*p;
	t_dlst	*p_last;
	
	p = min;
	p_last = min;
	while(p != max)
	{
		if(p->num < pivot->num)
		{
			p_last = p;
		}
		p = p->next;
	}
	printf("till: %d\n",p_last->num);
	while(a_head->next != p_last)
	{
		if(a_head->next->num < pivot->num)//ここを小なりイコールにするとバグる！なぜ？？？要修正
		{
			printf("a_head->next->num: %d\n", a_head->next->num);
			pb(a_head, b_head);
		}
		else
			ra(a_head);
	}
	pb(a_head, b_head);
}

bool	dlst_qsort(t_dlst *a_head, t_dlst *b_head, t_dlst *min, t_dlst *max)
{
	t_dlst	*pivot;
	t_dlst	*pre_piv;
	int	size;

	//少ない時の処理必要
	pivot = find_pivot(min, max);
	if (!pivot)
		return (false);
	printf("pivot: %d\n", pivot->num);
	arrange(a_head, b_head, min, max, pivot);
	size = dlst_size(b_head);
	if (size < 7)
	{
		if (size == 1)
			ft_putstr_fd("no need to change", 1);
		else if (size == 2)
			algo_2(b_head);
		else if (size == 3)
			algo_3(b_head);
		else if (size <= 6)
			algo_u6(b_head, a_head);
		moveb_to_aback_tilldone(a_head, b_head);
	}
	pre_piv = pivot->prev;
	//dlst_qsort(b_head, a_head, pivot, max);
	//dlst_qsort(a_head, b_head, min, pre_piv);
	return (true);
}

void	algo_o7(t_dlst *a_head, t_dlst *b_head)
{
	dlst_qsort(a_head, b_head, a_head->next, a_head->prev);
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
		algo_o7(a_head, b_head);
	print_stacks(a_head, b_head);
	return (0);
}
