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

int 	check_res(char *res, char *str)
{
	int i;
	char **tmp;

	i = 0;
	tmp = NULL;
	if (res)
		tmp = ft_strsplit(res, ' ');

	while (tmp && tmp[i])
	{
		if (ft_strcmp(tmp[i], str) == 0)
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

void	del_last(char *str)
{
	size_t len;

	len = ft_strlen(str) - 1;
	if (str[len] == ' ')
		str[len] = '\0';
	while (*str && str[len] != ' ')
	{
		str[len] = '\0';
		len--;
	}
}

char	*get_to(char *str, char *to)
{
	char	*hz;
	char 	**tmp;
	char 	*res;
	int 	i;

	i = 0;
	res = NULL;
	tmp = ft_strsplit(str, ' ');
	while (tmp[i] && ft_strcmp(tmp[i], to) != 0)
	{
		hz = ft_strjoin(res, tmp[i]);
		res = ft_strjoin(hz, " ");
		i++;
	}
	hz = ft_strjoin(res, tmp[i]);
	res = ft_strjoin(hz, " ");
	return (res);
}

int 	if_all_mark(t_graph *graph, t_node *node)
{

	while (node)
	{
		if (node->mark != 1)
			return (0);
		node = node->next;
	}
	return (1);
}

int 	check_end(char *str, char *end, t_graph *graph)
{
	char **tmp;
	int len;
	t_node *node;

	tmp = ft_strsplit(str, ' ');
	len = len_arr(tmp) - 2;
	node = graph->array[find_index(graph->array, tmp[len])].head;
	while (node)
	{
		if (ft_strcmp(node->dest, end) == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

void    rec_f(t_all *all, t_graph *graph, t_node *node, t_node *start)
{
	t_node *tmp;
	t_node *s;

	if (all->j++ == 0)
		all->ss = graph->array[find_index(graph->array, node->dest)].head;
	if (all->res[all->i] && check_res(all->res[all->i], node->dest) &&
			ft_strcmp(node->dest, all->end) != 0)
		return ;
	else
	{
		if (all->r_rec == 1)
		{
			all->i++;
			all->res[all->i] = get_to(all->res[all->i - 1], node->begin);
		}
		all->res[all->i] = ft_strjoin(all->res[all->i], " ");
		all->res[all->i] = ft_strjoin(all->res[all->i], node->dest);
		all->r_rec = 0;
	}
	if (ft_strcmp(node->dest, all->end) == 0)
	{

		all->r_rec = 1;
		return ;
	}
	while (node)
	{
		if (all->flag != 3)
			tmp = graph->array[find_index(graph->array, node->dest)].head;
		else
		{
			tmp = node;
			all->flag = 0;
		}
		node->mark = 1;
		rec_f(all, graph, tmp, start);
		node = tmp->next;
		all->flag = 3;
		if (if_all_mark(graph, all->ss) && node == NULL &&
				ft_strcmp(tmp->begin, all->ss->begin) == 0 &&
				start->next)
		{
			node = start->next;
			all->flag = 0;
			all->i++;
			all->r_rec = 0;
			all->res[all->i] = start->begin;
			all->res[all->i] = ft_strjoin(all->res[all->i], " ");
			all->res[all->i] = ft_strjoin(all->res[all->i], node->dest);
			start = start->next;
		}
	}
}