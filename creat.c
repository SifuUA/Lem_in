#include "lem_in.h"

t_graph	*creat_graph(long int count_v)
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

t_all	*creat_struct(long int count_vert, int count_links)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	all->start = NULL;
	all->end = NULL;
	all->verticies = (char **)malloc(sizeof(char*) * count_vert);
	all->links = (char **)malloc(sizeof(char*) * (count_links * 2) + 1);
	all->links[count_links] = NULL;
	all->link = count_links;
	all->res = (char **)malloc(sizeof(char*) * count_links * 10);
	all->fin_res = (char **)malloc(sizeof(char*) * count_links * 10);
	all->i = 0;
	all->r_rec = 0;
	all->j = 0;
	all->k = 0;
	all->tmp = NULL;
	return (all);
}