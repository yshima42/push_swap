/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/16 10:48:28 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	find_pivot(t_dlst *dlst_head, int size)
{
	int *array;
	int	pivot;

	array = dlst_to_array_pivot(dlst_head, size);
	array_qsort(array, 0, size - 1);
	pivot = array[(size - 1) / 2];
	free(array);
	return (pivot);
}

void	push_num_toB(t_stack *stack, int size, int pivot, int *n_ra, int *n_pb)
{
	t_dlst	*p;
	int i;
	
	p = stack->a_head->next;
	i = 0;
	while(i < size)
	{
		if(stack->a_head->next->num > pivot)
		{
			ra(stack);
			(*n_ra)++;
		}
		else
		{
			pb(stack);
			(*n_pb)++;
		}
		i++;
	}
	i = 0;
	if (stack->n_ABqsort == 1)
		ra(stack);
	else
		while(i < *n_ra)
		{
			rra(stack);
			i++;
		}
}


bool	qsort_BtoA(t_stack *stack, int size);

bool	qsort_AtoB(t_stack *stack, int size)
{
	int	pivot;
	int	n_ra;
	int n_pb;
	
	stack->n_ABqsort++;
	n_pb = 0;
	n_ra = 0;
	if (size == 1)
		return true;
	pivot = find_pivot(stack->a_head, size);
	push_num_toB(stack, size, pivot, &n_ra, &n_pb);
	qsort_AtoB(stack, n_ra);
	qsort_BtoA(stack, n_pb);
	return (true);
}

void	push_num_toA(t_stack *stack, int size, int pivot, int *n_pa, int *n_rb)
{
	t_dlst	*p;
	int i;
	
	stack->n_BAqsort++;
	p = stack->b_head->next;
	i = 0;
	while(i < size)
	{
		if(stack->b_head->next->num <= pivot)
		{
			rb(stack);
			(*n_rb)++;
		}
		else
		{
			pa(stack);
			(*n_pa)++;
		}
		i++;
	}
	i = 0;
	if (stack->n_BAqsort == 1)
		rb(stack);
	else
		while(i < *n_rb)
		{
			rrb(stack);
			i++;
		}
}

bool	qsort_BtoA(t_stack *stack, int b_size)
{
	int	pivot;
	int	n_pa;
	int	n_rb;

	if (b_size == 1)
	{
		pa(stack);
		return(true);
	}
	pivot = find_pivot(stack->b_head, b_size);
	n_pa = 0;
	n_rb = 0;
	push_num_toA(stack, b_size, pivot, &n_pa, &n_rb);
	qsort_AtoB(stack, n_pa);
	qsort_BtoA(stack, n_rb);
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
	elem->n_ABqsort = 0;
	elem->n_BAqsort = 0;
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
	return (0);
}
