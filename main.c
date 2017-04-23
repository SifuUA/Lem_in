#include <stdio.h>
#include <sys/fcntl.h>
#include "lem_in.h"


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