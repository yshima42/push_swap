
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

	print_stacks(a_head, b_head);

	dlst_push_top(a_head, b_head);
	printf("\n");

	print_stacks(a_head, b_head);
	
	return 0;
}
