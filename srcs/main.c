/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 01:32:19 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	ope_export(int ope)
{
	if (ope == PA)
		ft_putstr_fd("pa", 1);
	else if (ope == PB)
		ft_putstr_fd("pb", 1);
	else if (ope == SA)
		ft_putstr_fd("sa", 1);
	else if (ope == SB)
		ft_putstr_fd("sb", 1);
	else if (ope == SS)
		ft_putstr_fd("ss", 1);
	else if (ope == RA)
		ft_putstr_fd("ra", 1);
	else if (ope == RB)
		ft_putstr_fd("rb", 1);
	else if (ope == RR)
		ft_putstr_fd("rr", 1);
	else if (ope == RRA)
		ft_putstr_fd("rra", 1);
	else if (ope == RRB)
		ft_putstr_fd("rrb", 1);
	else if (ope == RRR)
		ft_putstr_fd("rrr", 1);
	else
		ft_putstr_fd("Error\n", 2);
}

void	ans_output(t_dlst *ans)
{
	t_dlst	*p;

	p = ans->next;
	while(p != ans)
	{
		ope_export(p->num);
		ft_putstr_fd("\n", 1);
		p = p->next;
	}
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
	if (a_head->next->num > a_head->next->next->num)
		sa(stack);
	else
		;//ft_putstr_fd("no need to change\n", 1);
}

void	algo_3(t_dlst *a_head, t_stack *stack)
{
	int a;
	int b;
	int c;
	
	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->next->next->next->num;
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
		;//エラーハンドリングする
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
	t_dlst *p;

	p = stack->b_head->next;
	
	while(p != stack->b_head)
	{
		p = p->next;
		pa(stack);
	}
}

void	algo_u6(t_stack *stack)
{
	pushb_till_3(stack);
	algo_3(stack->a_head, stack);
	pusha_3_times(stack);
}

//消す
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

void	init_count(t_count *count)
{
	count->n_pb = 0;
	count->n_ra = 0;
	count->n_rb = 0;
	count->n_pa = 0;
}

int	*dlst_to_array_pivot(t_dlst *dlst_head, int size)
{
	int	*array;
	t_dlst *p;
	int i;
	
	p = dlst_head->next;
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)//perrorつける //後ほどフリーする
		exit(EXIT_FAILURE);
	i = -1;
	while(++i < size)
	{
		array[i] = p->num;
		p = p->next;
	}
	//NULL埋めしなくて大丈夫か？
	return (array);
}

void	find_pivot(t_dlst *dlst_head, int size, int *s_pivot, int *l_pivot)
{
	int *array;

	array = dlst_to_array_pivot(dlst_head, size);
	array_qsort(array, 0, size - 1);
	*s_pivot = array[size / 3];
	*l_pivot = array[size * 2 / 3];
	free(array);
}

void	push_num_toB(t_stack *stack, int size, int s_pivot, int l_pivot, t_count *count)
{
	int i;
	int j;
	
	i = 0;

	while(i < size)
	{
		if(stack->a_head->next->num >= l_pivot)
		{
			ra(stack);
			(count->n_ra)++;
		}
		else
		{
			pb(stack);
			(count->n_pb)++;
			if (stack->b_head->next->num > s_pivot)
			{
				rb(stack);
				(count->n_rb)++;
			}
		}
		i++;
	}
	i = 0;
	j = 0;
	if (count->n_ra < count->n_rb)
	{
		while(i < count->n_ra)
		{
			rrr(stack);
			i++;
		}
		while (j < count->n_rb - count->n_ra)
		{
			rrb(stack);
			j++;
		}
	}
	else if (count->n_rb < count->n_ra)
	{
		while(i < count->n_rb)
		{
			rrr(stack);
			i++;
		}
		while (j < count->n_ra - count->n_rb)
		{
			rra(stack);
			j++;
		}
	}
	else
		while(i < count->n_rb)
			{
				rrr(stack);
				i++;
			}
}


bool	qsort_BtoA(t_stack *stack, int size);

bool	checker(t_dlst *a_head)
{
	if (a_head->next->num > a_head->next->next->num && a_head->next->next->num > a_head->next->next->next->num)
		return(1);
	else
		return(0);
}

void	temp_algo_3(t_dlst *a_head, t_stack *stack)
{
	int a;
	int b;
	int c;
	
	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->next->next->next->num;
	if (b < a && a < c)
		sa(stack);
	else if (b < c && c < a)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (c < b && b < a)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
	else if (a < c && c < b)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (c < a && a < b)
	{
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
	else
		;//エラーハンドリングする
}

bool	qsort_AtoB(t_stack *stack, int size)
{
	int	s_pivot;
	int	l_pivot;
	t_count	count;
	
	init_count(&count);
	if (size == 0)
		return (true);
	if (size == 1)
		return true;
	if (size == 2)
	{
		algo_2(stack->a_head, stack);
		return true;
	}
	if (size == 3)
	{
		temp_algo_3(stack->a_head, stack);
		return true;
	} 
	find_pivot(stack->a_head, size, &s_pivot, &l_pivot);
	/* printf("---AtoB---\ns_p: %d\nl_p: %d\n", s_pivot, l_pivot);
	//printf("---0st---\n");
	print_stacks(stack);
	printf("size: %d\n",size); */
	push_num_toB(stack, size, s_pivot, l_pivot, &count);
	/* printf("---1st---\n");
	print_stacks(stack);*/
	//printf("ra: %d\n",count.n_ra);
	qsort_AtoB(stack, count.n_ra); 
	/* printf("---2nd---\n");
	print_stacks(stack); */
	/* printf("n_rb: %d\n", count.n_rb);
	printf("n_pb: %d, n_rb: %d\n",count.n_pb,  count.n_rb); */
	qsort_BtoA(stack, count.n_rb);
	/* printf("---3rd---\n");
	print_stacks(stack);
	printf("n_pb: %d, n_rb: %d\n",count.n_pb,  count.n_rb);
	printf("size: %d\n", size); */
	qsort_BtoA(stack, count.n_pb - count.n_rb);
	/* printf("---END---\n");
	print_stacks(stack); */
	return (true);
}

void	push_num_toA(t_stack *stack, int size, int s_pivot, int l_pivot, t_count *count)
{
	int i;
	
	i = 0;
	while(i < size)
	{
		if(stack->b_head->next->num <= s_pivot)
		{
			rb(stack);
			(count->n_rb)++;
		}
		else
		{
			pa(stack);
			(count->n_pa)++;
			if (stack->a_head->next->num < l_pivot)
			{
				ra(stack);
				(count->n_ra)++;
			}
		}
		i++;
	}
}

void	revierse_stack(t_stack *stack, t_count *count)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (count->n_ra < count->n_rb)
	{
		while(i < count->n_ra)
		{
			rrr(stack);
			i++;
		}
		while (j < count->n_rb - count->n_ra)
		{
			rrb(stack);
			j++;
		}
	}
	else if (count->n_rb < count->n_ra)
	{
		while(i < count->n_rb)
		{
			rrr(stack);
			i++;
		}
		while (j < count->n_ra - count->n_rb)
		{
			rra(stack);
			j++;
		}
	}
	else
		while(i < count->n_rb)
			{
				rrr(stack);
				i++;
			}
}

void	_algo_2(t_dlst *head, t_stack *stack)
{
	if (head->next->num < head->next->next->num)
		sb(stack);
	else
		;
}

void	_algo_3(t_dlst *a_head, t_stack *stack)
{
	int a;
	int b;
	int c;
	
	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->next->next->next->num;
	if (b < a && a < c)
	{
		rb(stack);
		sb(stack);
		pa(stack);
		rrb(stack);
		pa(stack);
		pa(stack);
	}
	else if (b < c && c < a)
	{
		pa(stack);
		sb(stack);
		pa(stack);
		pa(stack);
	}
	else if (a < c && c < b)
	{
		sb(stack);
		pa(stack);
		sb(stack);
		pa(stack);
		pa(stack);
	}
	else if (c < a && a < b)
	{
		sb(stack);
		pa(stack);
		pa(stack);
		pa(stack);
	}
	else if (a < b && b < c)
	{
		rb(stack);
		sb(stack);
		pa(stack);
		pa(stack);
		rrb(stack);
		pa(stack);
	}
	else
	{
		pa(stack);
		pa(stack);
		pa(stack);
	};//エラーハンドリングする
}

bool	qsort_BtoA(t_stack *stack, int b_size)
{
	int	s_pivot;
	int	l_pivot;
	t_count	count;

	init_count(&count);
	if (b_size == 0)
		return (true);	
	if (b_size == 1)
	{
		pa(stack);
		return(true);
	}
	if (b_size == 2)
	{
		_algo_2(stack->b_head, stack);
		pa(stack);
		pa(stack);
		return (true);
	}
	if (b_size == 3)
	{
		_algo_3(stack->b_head, stack);
		return true;
	}
	find_pivot(stack->b_head, b_size, &s_pivot, &l_pivot);
	push_num_toA(stack, b_size, s_pivot, l_pivot, &count);
	qsort_AtoB(stack, count.n_pa - count.n_ra);//ここ怪しい
	revierse_stack(stack, &count);
	qsort_AtoB(stack, count.n_ra);
	qsort_BtoA(stack, count.n_rb);
	return true;
}

void	algo_o7(t_stack *stack)
{
	qsort_AtoB(stack, dlst_size(stack->a_head));
}

t_stack	*stack_init(void)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if(!elem)
	{
		perror("Error\nmalloc");
		exit(EXIT_FAILURE);
	}
	elem->a_head = dlst_init();
	elem->b_head = dlst_init();
	elem->ans = dlst_init();
	return (elem);
}

void	array_qsort(int *array, int start, int end)
{
	int	tmp;
	int	pivot;
	int	i;
	int	j;
	
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
				break;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		array_qsort(array, start, i - 1);
		array_qsort(array, j + 1, end);
	}
}

void	av_to_dlst(t_stack *stack, int ac, char **av)
{
	int	i;
	int	num;
	
	i = 0;
	
	while (++i < ac)
	{
		num = ft_atoi(av[i]);
		dlst_add_back(stack->a_head, dlst_new(num));
	}
}

int	*dlst_to_array(t_dlst *a_head)
{
	int	size;
	int	*array;
	t_dlst *p;
	int i;
	
	p = a_head->next;
	size = dlst_size(a_head);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)//perrorつける //後ほどフリーする
		exit(EXIT_FAILURE);
	i = 0;
	while(p != a_head)
	{
		array[i] = p->num;
		i++;
		p = p->next;
	}
	//NULL埋めしなくて大丈夫か？
	return (array);
}

int	sub_check(int *array)
{
	int	a_sub;
	a_sub = -1;
	while(array[++a_sub])
		;
	a_sub--;
	return(a_sub);
}

void	input_order_num(t_dlst *a_head, int *array)
{
	t_dlst	*p;
	int	i;
	
	p = a_head->next;
	while (p != a_head)
	{
		i = -1;
		while (array[++i])
		{
			if (p->num == array[i])
				p->order = i;
		}
		p = p->next;
	}
}

void	set_order(t_stack *stack)
{
	int *array;
	int a_sub;
	
	array = dlst_to_array(stack->a_head);
	a_sub = sub_check(array);
	array_qsort(array, 0, a_sub);
	input_order_num(stack->a_head, array);
	free(array);
}

void
	dlst_replace(t_dlst *ans, int ope)
{
	t_dlst	*p;

	p = ans->next->next->next;
	free(ans->next->next);
	ans->next->next = NULL;
	ans->next->num = ope;
	ans->next->next = p;
	p->prev = ans->next;
}

void	ans_shorten(t_dlst *ans)
{
	t_dlst	*p;

	p = ans->next;
	while(p != ans)
	{
		if (p->next->num == SA && p->next->next->num == SB)
			dlst_replace(p, SS);
		if (p->next->num == SB && p->next->next->num == SA)
			dlst_replace(p, SS);
		if (p->next->num == RA && p->next->next->num == RB)
			dlst_replace(p, RR);
		if (p->next->num == RB && p->next->next->num == RA)
			dlst_replace(p, RR);
		if (p->next->num == RRA && p->next->next->num == RRB)
			dlst_replace(p, RR);
		if (p->next->num == RRB && p->next->next->num == RRA)
			dlst_replace(p, RRR);
		p = p->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	args_check(ac, av);
	stack = stack_init();
	av_to_dlst(stack, ac, av);
	set_order(stack);
	ac--;
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
	ans_shorten(stack->ans);
	ans_output(stack->ans);
	return (0);
}
