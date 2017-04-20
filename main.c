#include "lem_in.h"

/*void	get_mem(char **line)
{
	**line = (**line)
}*/

int 	count_ver(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (ft_strchr())
		}
	}
}

t_graph	*creat_graph(int count_v)
{
	t_graph * graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->count_vert =

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
	creat_graph(count_ver(save));
}

