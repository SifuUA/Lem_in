#include "lem_in.h"

int 	check_res(char **res, char *str)
{
	int i;

	i = 0;
	while (res[i])
	{
		if (ft_strcmp(res[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	rec_f(t_all *all, t_graph *graph, int *res, int move, char *start)
{
	t_node *node;

	node = graph->array[find_index(graph->array, start)].head;
	if (check_res(all->res, node->dest))
		return ;
	all->res[all->i] = ft_strjoin(all->res[all->i], node->dest);
	all->i++;
	while (node)
	{
		start = node->dest;
		node->mark = 1;
		rec_f(all, graph, res, move + 1, start);
		node = node->next;
	}









	//res[move] = graph->array[move];


	/*while (i < graph->count_vert)
	{
		ptr = array[i].head;
		while (ptr) {
			ptr->mark = 0;
			ptr = ptr->next;
		}
		i++;
	}*/
}