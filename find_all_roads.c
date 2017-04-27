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

struct s_node * find_node(t_graph *graph, char *dest, char *begin)
{
	int i;
	t_node *tmp;

	i = 0;
	while (i < graph->count_vert)
	{
		tmp = graph->array[i].head;
		while (tmp)
		{
			if (ft_strcmp(tmp->dest, dest) == 0
				&& ft_strcmp(tmp->begin, begin) == 0)
				return (graph->array[i].head);
			tmp = tmp->next;
		}
		i++;
	}
	return (NULL);
}

void	rec_f(t_all *all, t_graph *graph, int *res, char *dest, char *begin)
{
	t_node *node;

	node = find_node(graph, dest, begin);
	if (check_res(all->res, node->dest))
		return;
	all->res[all->i] = ft_strjoin(all->res[all->i], node->dest);
	all->i++;
	while (node)
	{
		node->mark = 1;
		node = graph->array[find_index(graph->array, begin)].head;
		rec_f(all, graph, res, node->dest, node->begin);
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