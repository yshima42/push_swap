
#include "../includes/push_swap.h"

void	dlst_free(t_dlst *head)
{
	t_dlst	*p;

	p = head->next;
	while(p != head)
	{
		p = p->next;
		free (p->prev);
	}
	free (head);
}

void	all_free(t_stack *stack)
{
	if (stack->a_head)
		dlst_free(stack->a_head);
	if (stack->b_head)
		dlst_free(stack->b_head);
	if (stack->ans)
		dlst_free(stack->ans);
	if (stack)
		free(stack);
}
