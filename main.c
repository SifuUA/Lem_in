#include <stdio.h>
#include <sys/fcntl.h>
#include "lem_in.h"

char	**read_and_write()
{

	char	*line;
	char	**save;
	int 	fd;
	int 	i;

	i = 0;
//	fd = open("ant_farms_samples/test", O_RDONLY);
	save = (char **)malloc(sizeof(char*) * 10000);
//	while (get_next_line(fd, &line) && *line != 0)
	while (get_next_line(0, &line) && *line != 0)
	{
		save[i++] = line;
	}
	//close(fd);
	ft_strdel(&line);
	return (save);
}

void	mem_clear(t_all *all, char **save, t_graph *graph, t_node *node_start)
{
	long int i;
	t_node *node;

	i = 0;
	if (all->verticies)
		free_arr(all->verticies);
	all->verticies = NULL;
	if (all->links)
		free_arr(all->links);
	all->links = NULL;
	if (all->res)
		free_arr(all->res);
	all->res = NULL;
	if (all->fin_res)
		free_arr(all->fin_res);
	all->fin_res = NULL;
	if (all->ss)
		free(all->ss);
	all->ss = NULL;
	if (all->start)
		free(all->start);
	all->start = NULL;
	if (all->end)
		free(all->end);
	all->end = NULL;
	if (all->dest)
		free(all->dest);
	all->dest = NULL;
	if (all->tmp)
		free(all->tmp);
	if (all->stoper)
		free(all->stoper);
	if (all->storage)
		free(all->storage);
	all->tmp = NULL;
	free(all);
	if (save)
		free_arr(save);
	if (node_start)
		free(node_start);
	/*while (graph->array[i].head)
	{
		node = graph->array->head;
		while (node)
		{
			free(node);
			node = node->next;
		}
		i++;
	}*/

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
	fill_all(all, save);// лик
	check(all);
	graph = creat_graph(count_v);
	fill_graph(graph, all, count_links(save));
	node_start = find_node(graph, all->dest, all->start);
	all->res[0] = node_start->begin;
	rec_f(all, graph, node_start, 0);
	all->res[all->i + 1] = NULL;
	all->fin_res[all->k] = NULL;
	choose_ways(all);
	mem_clear(all, save, graph, node_start);
	//sleep(30);
}