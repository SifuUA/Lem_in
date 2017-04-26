#include "lem_in.h"

void	rec_f(t_all *all, t_graph *graph, t_head *array)
{
	t_node *ptr;
	int i;

	i = 0;
	while (i < graph->count_vert)
	{
		ptr = array[i].head;
		while (ptr) {
			ptr->mark = 0;
			ptr = ptr->next;
		}
		i++;
	}
}