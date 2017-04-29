#include "lem_in.h"

int 	check_res_mod(char **res, char *str)
{
	int i;
	int j;
	char **tmp;

	i = 0;
	j = 0;
	while (res && res[i])
	{
		tmp = ft_strsplit(res[i], ' ');
		while (tmp[j])
		{
			if (ft_strcmp(tmp[j], str) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}

int 	check_res(char **res, char *str)
{
	int i;

	i = 0;
	while ( res && res[i])
	{
		if (ft_strcmp(res[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

struct s_node * find_node(t_graph *graph, char *dest, char *begin)
{
	int i;
	t_node *tmp;

	i = 0;
	while (i < graph->count_vert)
	{
		tmp = graph->array[i].head;
		while (tmp)
		{
			if (ft_strcmp(tmp->dest, dest) == 0
				&& ft_strcmp(tmp->begin, begin) == 0)
				return (graph->array[i].head);
			tmp = tmp->next;
		}
		i++;
	}
	return (NULL);
}

void	clear_mark(t_graph *graph)
{
	t_node *ptr;

	int i;

	i = 0;
	while (i < graph->count_vert)
	{
		ptr = graph->array[i].head;
		while (ptr) {
			ptr->mark = 0;
			ptr = ptr->next;
		}
		i++;
	}
}

int 	get_index(char **str, char *st)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], st) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	rec_f(t_all *all, t_graph *graph, t_node *node, t_node *start)
{
	t_node *tmp;
	char **st; 
	int c;

	c = 0;
	if (all->j == 0)
	{
		all->res[all->i] = start->begin;
		all->j++;
	}
<<<<<<< Updated upstream
	/*if (check_res(ft_strsplit(all->res[all->i], ' '), node->dest))
		return;*/
	if (check_res_mod(all->res, node->dest))
		return ;
=======
	if (check_res(ft_strsplit(all->res[all->i], ' '), node->dest))
		return;
>>>>>>> Stashed changes
	if (ft_strcmp(node->dest, all->end) == 0)
	{
		st = ft_strsplit(all->res[all->i], ' ');
		all->i++;
		while (c <= get_index(st, node->begin))
		{
			all->res[all->i] = ft_strjoin(all->res[all->i], st[c]);
			all->res[all->i] = ft_strjoin(all->res[all->i], " ");
			c++;
		}
		return ;
	}
	all->res[all->i] = ft_strjoin(all->res[all->i], " ");
	all->res[all->i] = ft_strjoin(all->res[all->i], node->dest);
	while (node)
	{
		node->mark = 1;
		if (all->flag != 3)
			tmp = graph->array[find_index(graph->array, node->dest)].head;
		else
		{
			tmp = node;
			all->flag = 0;
		}
		rec_f(all, graph, tmp, start);
		node = tmp->next;
		all->flag = 3;
	}
}