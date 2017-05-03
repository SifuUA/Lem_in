#include "lem_in.h"

int 	ft_strchr_arr(char **arr, char *str)
{
	int i;

	i = 0;
	if (!str || !arr)
		return (-1);
	while (arr[i])
	{
		if (ft_strcmp(arr[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
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