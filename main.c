#include <stdio.h>
#include <sys/fcntl.h>
#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_graph	*graph;
	t_all 	*all;
	char	*line;
	char	**save;
	int 	**matrix;
	int fd;
	int i;

	i = 0;
	fd = open("ant_farms_samples/test7", O_RDONLY);
	save = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(fd, &line) && *line != 0)
	{
		save[i++] = line;
	}
	//ft_arr_putstr(save);
	all = creat_struct(count_vert(save), count_links(save));
	fill_all(all, save);
	check(all);
	//визуализация
	/*ft_arr_putstr(all->links);
	ft_putstr("***\n");
	ft_arr_putstr(all->verticies);
	*/

	graph = creat_graph(count_vert(save));
	fill_graph(graph, all, count_links(save));
	graph->count_links = count_links(save) * 2;
//	print_graph(graph);

	int *arr = malloc(sizeof(int) * graph->count_vert);
	t_node *node_start = find_node(graph, all->dest, all->start);
	all->res[0] = node_start->begin;

	//rec_f()
	rec_f(all, graph, node_start, 0);
	all->res[all->i + 1] = NULL;
	ft_arr_putstr(all->fin_res);
	//ft_arr_putstr(all->res);
	//matrix = creat_matrix(count_vert(save));
	//fill_matrix(matrix, all, count_vert(save));

	close(fd);
}