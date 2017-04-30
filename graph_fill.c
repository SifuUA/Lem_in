#include "lem_in.h"

void	print_graph(t_graph *graph)
{
	int i;
	t_node *node;

	i = 0;
	while (i < graph->count_vert)
	{
		node = graph->array[i].head;
		ft_putstr("\n Adjency list:\n");
		ft_putstr(node->begin);
		while (node)
		{
			ft_putstr(" -> ");
			ft_putstr(node->dest);
			node = node->next;
		}
		ft_putstr("\n");
		i++;
	}
}

int		find_index(t_head *arr, char *str)
{
	char *p;
	static int j;
	int i;
	int flag;

	i = 0;
	flag = 0;
	p = NULL;
	if (arr[i].head)
		p = arr[i].head->begin;
	while (p)
	{
		if (ft_strcmp(p, str) == 0)
			return (i);
		if (arr[i + 1].head && arr[i + 1].head->begin && arr[i + 1].head->dest)
			p = arr[i + 1].head->begin;
		else
		{
			p = NULL;
			arr[i + 1].head = NULL;
			i++;
			continue;
			//flag = 1;
			//break ;
		}
		flag = 1;
		i++;
	}
	return (flag == 0 ? j++ : i);
}

t_node 	*add_node(char *begin, char *dest)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = NULL;
	node->dest = dest;
	node->begin = begin;
	node->mark = 0;
	return (node);
}

void	add_new(t_graph *graph, char *src, char *dest)
{
	t_node *node;
	int		index;


	node = add_node(src, dest);
	index = find_index(graph->array, src);
	node->next = graph->array[index].head;
	graph->array[index].head = node;

	node = add_node(dest, src);
	index = find_index(graph->array, dest);
	node->next = graph->array[index].head;
	graph->array[index].head = node;

}

void 	fill_graph(t_graph *graph, t_all *all, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < count)
	{
		add_new(graph, all->links[i], all->links[i + 1]);
		i += 2;
		j++;
	}
}

