#include "lem_in.h"

/*void	get_mem(char **line)
{
	**line = (**line)
}*/

/*int 	find_sharp(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '#' && str[i + 1] == '#')
			return (1);
		else
			return (0);
	}
	return (0);
}*/

int 	count_ver(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strchr(str[i], '#') == NULL && ft_strchr(str[i], '-') == NULL &&
				ft_strchr(str[i], ' '))
			count++;
		i++;
	}
	return (count);
}

char	*get_links(char **str)
{

}

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
	char	*line;
	char	**save;
	int i;

	i = 0;
	save = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(0, &line))
	{
		save[i++] = ft_strdup(line);
	}
	ft_arr_putstr(save);
	ft_putnbr(count_ver(save));
	graph = creat_graph(count_ver(save));
	add_links(graph, get_links(save));
}

