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

void	del_list(t_node *ss)
{

	while (ss)
	{
		free(ss);
		ss = ss->next;
	}
}

void	mem_clear(t_all *all, char **save, t_graph *graph, t_node *node_start)
{
	long int i;
	t_node *node;
	t_node *tmp_node;

	i = 0;
	if (all->verticies)
		free_arr(all->verticies);
	all->verticies = NULL;
	if (all->links)
		free_arr(all->links);
	all->links = NULL;
	//if (all->res)
	//	free_arr(all->res);
	//all->res = NULL;
	//if (all->fin_res)
	//	free_arr(all->fin_res);
	//all->fin_res = NULL;
	//del_list(all->ss);
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
	if (save)
		free_arr(save);
	//del_list(node_start);
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
	mem_clear(all, save, graph, node_start);
	sleep(15);
}