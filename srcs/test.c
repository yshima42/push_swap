
#include "main.c"

int main(void)
{
	//t_dlst *tmp;
/* 
	tmp = dlst_new(10);
	int i = 0;
	while (i < 4)
	{
		printf("%d\n",tmp->num);
		tmp = tmp->next;
		i++;
	} */

	t_stack	*stack;

	stack = stack_init();
	stack->a_head = dlst_init();
	stack->b_head = dlst_init();
	stack->info = info_init();

	dlst_add_back(stack->a_head, dlst_new(10));
	dlst_add_back(stack->a_head, dlst_new(20));
	dlst_add_front(stack->a_head, dlst_new(5));
	dlst_add_front(stack->a_head, dlst_new(3));

	dlst_add_back(stack->b_head, dlst_new(3));
	dlst_add_back(stack->b_head, dlst_new(4));
	dlst_add_front(stack->b_head, dlst_new(2));
	dlst_add_front(stack->b_head, dlst_new(1));

	print_stacks(stack);

	pb(stack);
	pb(stack);
	pb(stack);
	ra(stack);
	printf("\n");

	print_stacks(stack);
	
	return 0;
}
