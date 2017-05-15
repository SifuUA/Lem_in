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

char	**read_and_write()
{

	char	*line;
	char	**save;
	int 	i;

	i = 0;
	save = (char **)malloc(sizeof(char*) * 10000);
	while (get_next_line(0, &line) && *line != 0)
	{
		save[i++] = line;
	}
	ft_strdel(&line);
	return (save);
}

void	all_clear(t_all *all)
{
	if (all->verticies)
		free_arr(all->verticies);
	all->verticies = NULL;
	if (all->links)
		free_arr(all->links);
	all->links = NULL;
	all->ss = NULL;
	ft_strdel(&(all->start));
	ft_strdel(&(all->end));
	ft_strdel(&(all->dest));
	if (all->tmp)
		free(all->tmp);
	all->tmp = NULL;
	if (all->stoper)
		free(all->stoper);
	all->stoper = NULL;
	if (all->storage)
		free(all->storage);
	free(all);
}

void	mem_clear(char **save, t_graph *graph)
{
	long int i;
	t_node *node;
	t_node *tmp_node;

	i = 0;

	if (save)
		free_arr(save);
	while (graph->array[i].head)
	{
		node = graph->array[i].head;
		while (node)
		{
			ft_strdel(&(node->begin));
			ft_strdel(&node->dest);
			tmp_node = node->next;
			free(node);
			node = tmp_node;
		}
		graph->array[i].head = NULL;
		i++;
	}

}

int		main(int argc, char **argv)
{
	t_graph	*graph;
	t_all 	*all;
	t_node	*node_start;
	char 	**save;
	long int count_v;

	save = read_and_write();
	count_v = count_vert(save);
	all = creat_struct(count_v, count_links(save));
	fill_all(all, save);
	check(all);
	graph = creat_graph(count_v);
	fill_graph(graph, all, count_links(save));
	node_start = find_node(graph, all->dest, all->start);
	all->res[0] = ft_strdup(node_start->begin);
	rec_f(all, graph, node_start, 0);
	all->res[all->i + 1] = NULL;
	all->fin_res[all->k] = NULL;
	choose_ways(all);
	all_clear(all);
	mem_clear(save, graph);
}