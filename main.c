#include <stdio.h>
#include <sys/fcntl.h>
#include "lem_in.h"

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
		if (arr[i].head->next)
			p = arr[i].head->next->begin;
		else
		{
			i++;
			flag = 1;
			break ;
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

	/*node = add_node(dest, src);
	index = find_index(graph->array, dest);
	graph->array[index].head = node;*/

}

void 	fill_graph(t_graph *graph, t_all *all, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < count)
	{
		add_new(graph, all->links[i], all->links[i + 1]);
		i += 2;
	}
}

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
	ft_arr_putstr(all->links);
	ft_putstr("***\n");
	ft_arr_putstr(all->verticies);
	//edn

	graph = creat_graph(count_vert(save));
	fill_graph(graph, all, count_vert(save));


	//matrix = creat_matrix(count_vert(save));
	//fill_matrix(matrix, all, count_vert(save));

	close(fd);
}

//подсчет кол-ва комнат
//выделение памяти в структуре all под такое кол-во