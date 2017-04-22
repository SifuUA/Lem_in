#include <stdio.h>
#include <sys/fcntl.h>
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

t_all	*creat_struct(int count_vert, int count_links)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	all->start = NULL;
	all->end = NULL;
	all->verticies = (char *)malloc(sizeof(char) * count_vert);
	all->links = (char **)malloc(sizeof(char*) * count_links);
	all->vert = count_vert;
	all->link = count_links;
}
int		count_vert(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], '-') && !ft_strchr(str[i], '#') &&
				len_arr(ft_strsplit(str[i], ' ')) == 3)
			count++;
		i++;
	}
	return (count);
}

int		count_links(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strchr(str[i], '-') && !ft_strchr(str[i], '#') &&
			len_arr(ft_strsplit(str[i], '-')) == 2)
			count++;
		i++;
	}
	return (count);
}

int		main(int argc, char **argv)
{
	t_graph	*graph;
	t_all 	*all;
	char	*line;
	char	**save;
	int fd;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	save = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(fd, &line) && *line != 0)
	{
		save[i++] = line;
	}
	ft_arr_putstr(save);
	all = creat_struct(count_vert(save), count_links(save));
	fill_all(all, save);
	check(all);
	close(fd);
}

//подсчет кол-ва комнат
//выделение памяти в структуре all под такое кол-во