#include <stdio.h>
#include "lem_in.h"

t_graph	*creat_graph(int count_v)
{
	t_graph * graph;

	int i;

	i = 0;
	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->count_vert = count_v;
	graph->array = (t_head *)malloc(sizeof(t_head) * count_v);
	while (i < count_v)
	{
		graph->array[i].head = NULL;
		i++;
	}
	return (graph);
}

int		main(int argc, char **argv)
{
	t_graph	*graph;
	t_all 	*all;
	char	*line;
	char	**save;
	int i;

	i = 0;
	save = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(0, &line) && *line != '+')
	{
		save[i++] = line;
	}
	//ft_arr_putstr(save);
	find_vert(all, save);
}

//пробовать разбивать сплитом по пробелам и проверять к-во строк
//точно также по дефисам и смотреть или 2 строки