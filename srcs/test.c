
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

	t_dlst *a_head;
	t_dlst *b_head;
	//t_dlst *p;
	
	a_head = dlst_init();
	b_head = dlst_init();
	dlst_add_back(a_head, dlst_new(10));
	dlst_add_back(a_head, dlst_new(20));
	dlst_add_front(a_head, dlst_new(5));
	dlst_add_front(a_head, dlst_new(3));

	dlst_add_back(b_head, dlst_new(3));
	dlst_add_back(b_head, dlst_new(4));
	dlst_add_front(b_head, dlst_new(2));
	dlst_add_front(b_head, dlst_new(1));

	while(a_head->next->num != 20)
	{
		if(a_head->next->num < 11)
		{
			pb(a_head, b_head);
		}
		else
			ra(a_head);
	}
	pb(a_head, b_head);
	print_stacks(a_head, b_head);

	pa(a_head, b_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
	pa(a_head, b_head);

	ra(a_head);
	ra(a_head);
	ra(a_head);
	rra(a_head);
	rra(a_head);
	rra(a_head);

	print_stacks(a_head, b_head);
	
	return 0;
}
