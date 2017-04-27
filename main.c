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
	fd = open("test.txt", O_RDONLY);
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
	print_graph(graph);

	int *arr = malloc(sizeof(int) * graph->count_vert);
	int move;

	rec_f(all, graph, arr, move, all->start);
	//matrix = creat_matrix(count_vert(save));
	//fill_matrix(matrix, all, count_vert(save));

	close(fd);
}