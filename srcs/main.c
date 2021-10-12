/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/12 22:38:39 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef	struct s_dlst
{
	struct s_dlst *prev;
	int num;
	struct s_dlst *next;
} t_dlst;

typedef	struct s_info
{
	t_dlst	*biggest;
	t_dlst	*smallest;
	int	n_pb;
	int n_pa;
	int	n_ra;
} t_info;

typedef struct s_stack
{
	t_dlst	*a_head;
	t_dlst	*b_head;
	t_info	*info;
} t_stack;

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

//ok
t_dlst	*dlst_new(int num)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if (!elem)
		return (NULL);
	elem->prev = elem;
	elem->next = elem;
	elem->num = num;
	return (elem);
}

//ok
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

//ok
void	dlst_add_back(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return ;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

//ok
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

//ok
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

//ok
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

//ok
void	dlst_add_front(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return ;
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;
}

//ok
void	dlst_swap(t_dlst *a, t_dlst *b)
{
	t_dlst	*a_before;
	t_dlst	*b_after;
	
	if (!a || !b)
		return ;
	a_before = a->prev;
	b_after = b->next;
	if (a_before == b)
		return ;
	a_before->next = b;
	b->prev = a_before;
	b->next = a;
	a->prev = b;
	a->next = b_after;
	b_after->prev = a;
}

//ok
void	dlst_swap_front(t_dlst *head)
{
	if (!head)
		return ;
	dlst_swap(head->next, head->next->next);
}

//ok
void	dlst_rotate(t_dlst *head)
{
	t_dlst	*front;
	
	if (!head)
		return ;
	front = head->next;
	dlst_swap(head, front);
}

//ok
void	dlst_rev_rotate(t_dlst *head)
{
	t_dlst	*back;
	
	if (!head)
		return ;
	back = head->prev;
	dlst_swap(back, head);
}

void	dlst_push_top(t_dlst *from_head, t_dlst *to_head)
{
	t_dlst *elem;
	
	elem = from_head->next->next;
	dlst_add_front(to_head, from_head->next);
	elem->prev = from_head;
	from_head->next = elem;
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

void	print_stacks(t_stack *stack)
{
	t_dlst *p;
	
	p = stack->a_head->next;
	while(p != stack->a_head)
	{
		printf("A: %d\n",p->num);
		p = p->next;
	}
	printf("\n");
	p = stack->b_head->next;
	while(p != stack->b_head)
	{
		printf("B: %d\n",p->num);
		p = p->next;
	}
}

void	av_to_a(t_stack *stack, char **av)
{
	size_t	i;
	int	num;
	
	i = 0;
	
	while (av[++i])
	{
		num = ft_atoi(av[i]);
		dlst_add_back(stack->a_head, dlst_new(num));
		/* if (num < info->smallest->num)
			info->smallest = a_head->prev;
		if (num > info->biggest->num)
			info->biggest = a_head->prev; */
	}
	/* info->smallest = a_head->next;
	info->biggest = a_head->next;
	printf("smallest: %d\n", info->smallest->num);
	printf("biggest: %d\n", info->biggest->num); */
}

void	sa(t_stack *stack)
{
	dlst_swap_front(stack->a_head);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	dlst_swap_front(stack->b_head);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack)
{
	dlst_swap_front(stack->a_head);
	dlst_swap_front(stack->b_head);
	ft_putstr_fd("ss\n", 1);
}

void	ra(t_stack *stack)
{
	dlst_rotate(stack->a_head);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	dlst_rotate(stack->b_head);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack)
{
	dlst_rotate(stack->a_head);
	dlst_rotate(stack->b_head);
	ft_putstr_fd("rr\n", 1);	
}

void	rra(t_stack *stack)
{
	dlst_rev_rotate(stack->a_head);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	dlst_rev_rotate(stack->b_head);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack)
{
	dlst_rev_rotate(stack->a_head);
	dlst_rev_rotate(stack->b_head);
	ft_putstr_fd("rrr\n", 1);
}

void	pa(t_stack *stack)
{
	dlst_push_top(stack->b_head, stack->a_head);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack)
{
	dlst_push_top(stack->a_head, stack->b_head);
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

void	algo_2(t_dlst *a_head, t_stack *stack)
{
	if (a_head->next->num > a_head->prev->num)
		sa(stack);
	else
		ft_putstr_fd("no need to change\n", 1);
}

void	algo_3(t_dlst *a_head, t_stack *stack)
{
	int a;
	int b;
	int c;
	
	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->prev->num;
	if (b < a && a < c)
		sa(stack);
	else if (b < c && c < a)
		ra(stack);
	else if (c < b && b < a)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < c && c < b)
	{
		sa(stack);
		ra(stack);
	}
	else if (c < a && a < b)
		rra(stack);
	else
		ft_putstr_fd("same numbers or no need to change\n", 2);//エラーハンドリングする
}

void	pushb_till_3(t_stack *stack)
{
	t_dlst	*p;
	t_dlst	*p_s;
	int		size;

	size = dlst_size(stack->a_head);
	while(size > 3)
	{
		p = stack->a_head->next;
		p_s = stack->a_head->next;
		while(p != stack->a_head)
		{
			if (p->num < p_s->num)
				p_s = p;
			p = p->next;
		}
		if (is_closer_front(stack->a_head, p_s))
		{
			while(stack->a_head->next != p_s)
				ra(stack);
		}
		else
		{
			while(stack->a_head->next != p_s)
				rra(stack);
		}
		pb(stack);
		size = dlst_size(stack->a_head);
	}
}

void	addback_to_a_tilldone(t_stack *stack)
{
	while(stack->b_head->next != stack->b_head)
	{
		pa(stack);
		ra(stack);
	}
}

void	pusha_3_times(t_stack *stack)
{
	int i;

	i = -1;
	while(++i < 3)
		pa(stack);
}

void	algo_u6(t_stack *stack)
{
	pushb_till_3(stack);
	algo_3(stack->a_head, stack);
	pusha_3_times(stack);
}

int	med3(int a, int b, int c)
{
	if (a < b)
		if (b < c)
			return (b);
		else if (a < c)
			return (c);
		else
			return (a);
	else
		if (a < c)
			return (a);
		else if (b < c)
			return (c);
		else
			return (b);
}

int	find_pivot(t_dlst *a_head, int size)
{
	int	i;
	int	middle;
	t_dlst	*p;
	
	i = 0;
	if (size < 2)
		return (0);
	p = a_head->next;
	while(i < size)
	{
		if(i == size / 2)
			middle = p->num;
		p = p->next;
		i++;
	}
	printf("確認：%d, %d, %d\n",a_head->next->num, middle, p->prev->num);
	return (med3 (a_head->next->num, middle, p->prev->num));
}

void	push_snum_toB(t_stack *stack, int size, int pivot)
{
	t_dlst	*p;
	t_dlst	*p_last;
	int i;
	
	p = stack->a_head->next;
	p_last = stack->a_head->next;
	i = 0;
	while(i < size)
	{
		if(stack->a_head->next->num >= pivot)
		{
			ra(stack);
			stack->info->n_ra++;
		}
		else
		{
			pb(stack);
			stack->info->n_pb++;
		}
		i++;
	}
	i = 0;
	//元に戻してる（必要か？）
	while(i < stack->info->n_ra)
	{
		rra(stack);
		i++;
	}
}

void	push_snum_toA(t_stack *stack, int size, int pivot)
{
	t_dlst	*p;
	t_dlst	*p_last;
	int i;
	
	p = stack->b_head->next;
	p_last = stack->b_head->next;
	i = 0;
	while(i < size)
	{
		if(stack->b_head->next->num <= pivot)
		{
			rb(stack);
		}
		else
		{
			pa(stack);
			stack->info->n_pa++;
			printf("a");
		}
		i++;
	}
}

bool	qsort_BtoA(t_stack *stack, int size);

bool	qsort_AtoB(t_stack *stack, int size)
{
	int	pivot;
	//少ない時の処理必要
	if (size == 1)
		return true;
	pivot = find_pivot(stack->a_head, size);
	//sizeが1だったら終わる処理を入れる
	printf("pivot: %d\n", pivot);
	stack->info->n_pb = 0;
	stack->info->n_ra = 0;
	push_snum_toB(stack, size, pivot);
/* 
	//このif文内、a_headとb_headを入れ替えてるからpaなどの表示が逆になってるはず
	int b_size;
	b_size = dlst_size(stack->b_head);
	if (b_size < 7)
	{
		if (b_size == 1)
			ft_putstr_fd("no need to change", 1);
		else if (b_size == 2)
			algo_2(stack->b_head);
		else if (b_size == 3)
			algo_3(stack->b_head);
		else if (b_size <= 6)
			algo_u6(stack->b_head, stack->a_head);
		//ここでsmallest見つける
		info->smallest = stack->b_head->next;
		printf("smallest: %d\n", info->smallest->num);
	}
 	else
	 	return(0);//qsort_AtoB(b_head, a_head, b_head->next, b_head->prev, info); */ 
	//下記を後で追加
	//addback_to_a_tilldone(a_head, b_head);
	printf("ra: %d\n", stack->info->n_ra);
	qsort_AtoB(stack, stack->info->n_ra);
	printf("hellooo\n");//ここで二回回ってる？？なぜ 3回？？ok
	printf("pb: %d\n", stack->info->n_pb);//ここが1なのがおかしい
	//qsort_BtoA(stack, stack->info->n_pb);
	//qsort_AtoB(b_head, a_head, b_head->next, b_head->prev);
	//printf("a_head->next->num: %d\ninfo->smallest->prev->num: %d\n",stack->a_head->next->num, info->smallest->num);
	//qsort_AtoB(a_head, b_head, a_head->next, info->smallest->prev, info);//ここでa_head側再帰
	return (true);
}

bool	qsort_BtoA(t_stack *stack, int b_size)
{
	int	pivot;

	if (b_size == 1)
	{
		pa(stack);
		return(true);
	}
	pivot = find_pivot(stack->b_head, b_size);
	printf("pivot: %d\n", pivot);
	stack->info->n_pa = 0;
	//push_snum_toA(stack, b_size, pivot);
	printf("pb: %d\n",stack->info->n_pb);
	printf("pa: %d\n",stack->info->n_pa);
	printf("size: %d\n",dlst_size(stack->b_head));
	//qsort_AtoB(stack, stack->info->n_pa);
	//qsort_BtoA(stack, dlst_size(stack->b_head));
	
	return true;
}

void	algo_o7(t_stack *stack)
{
	qsort_AtoB(stack, dlst_size(stack->a_head));
}

t_info	*info_init(void)
{
	t_info	*elem;

	elem = (t_info *)malloc(sizeof(t_info));
	if(!elem)
	{
		ft_putstr_fd("malloc error", 2);
		exit(1);
	}
	elem->n_pa = 0;
	elem->n_pb = 0;
	return (elem);
}

t_stack	*stack_init(void)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if(!elem)
	{
		ft_putstr_fd("malloc error", 2);
		exit(1);
	}
	return (elem);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int	n_num;

	args_check(ac, av);
	stack = stack_init();
	stack->a_head = dlst_init();
	stack->b_head = dlst_init();
	stack->info = info_init();
	av_to_a(stack, av);
	n_num = ac--;
	if (ac == 1)
		ft_putstr_fd("no need to change", 1);
	else if (ac == 2)
		algo_2(stack->a_head, stack);
	else if (ac == 3)
		algo_3(stack->a_head, stack);
	else if (ac <= 6)
		algo_u6(stack);
	else
		algo_o7(stack);
	print_stacks(stack);
	return (0);
}
