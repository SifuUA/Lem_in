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

int 	**creat_matrix(int size)
{
	int **matrix;
	int i;
	int j;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		matrix[i] = (int *)malloc(sizeof(int) * size + 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix[i][j] = 0;
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	return (matrix);
}

t_all	*creat_struct(int count_vert, int count_links)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	all->start = NULL;
	all->end = NULL;
	all->verticies = (char **)malloc(sizeof(char*) * count_vert);
	all->links = (char **)malloc(sizeof(char*) * (count_links * 2));
	all->vert = count_vert;
	all->link = count_links;
	return (all);
}