#include <stdio.h>
#include <sys/fcntl.h>
#include "lem_in.h"

void	read_and_write(t_all **all, t_graph **graph)
{

	char	*line;
	char	**save;
	t_node	*node_start;
	int 	fd;
	int 	i;

	i = 0;
	fd = open("ant_farms_samples/test11", O_RDONLY);
	save = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(fd, &line) && *line != 0)
	{
		save[i++] = line;
	}
	*all = creat_struct(count_vert(save), count_links(save));
	fill_all(*all, save);
	check(*all);
	*graph = creat_graph(count_vert(save));
	fill_graph(*graph, *all, count_links(save));
	node_start = find_node(*graph, (*all)->dest, (*all)->start);
	(*all)->res[0] = node_start->begin;
	rec_f(*all, *graph, node_start, 0);
	(*all)->res[(*all)->i + 1] = NULL;
	(*all)->fin_res[(*all)->k + 1] = NULL;
	//ft_arr_putstr((*all)->fin_res);
	close(fd);
}

int		main(int argc, char **argv)
{
	t_graph	*graph;
	t_all 	*all;

	read_and_write(&all, &graph);
	choose_ways(all);
}