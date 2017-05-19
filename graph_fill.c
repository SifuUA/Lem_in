/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:18:18 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 16:19:16 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_index_help(int *i, int *flag, char **p)
{
	*i = 0;
	*flag = 0;
	*p = NULL;
}

int		find_index(t_head *arr, char *str)
{
	char		*p;
	static int	j;
	int			i;
	int			flag;

	find_index_help(&i, &flag, &p);
	if (arr[i].head)
		p = arr[i].head->begin;
	while (p)
	{
		if (ft_strcmp(p, str) == 0)
			return (i);
		if (arr[i + 1].head && arr[i + 1].head->begin && arr[i + 1].head->dest)
			p = arr[i + 1].head->begin;
		else
		{
			p = NULL;
			arr[i + 1].head = NULL;
			i++;
			continue;
		}
		flag = 1;
		i++;
	}
	return (flag == 0 ? j++ : i);
}

t_node	*add_node(char *begin, char *dest)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = NULL;
	node->dest = ft_strdup(dest);
	node->begin = ft_strdup(begin);
	node->mark = 0;
	return (node);
}

void	add_new(t_graph *graph, char *src, char *dest, t_all *all)
{
	t_node	*node;
	int		index;

	node = add_node(src, dest);
	index = find_index(graph->array, src);
	node->next = graph->array[index].head;
	graph->array[index].head = node;
	node = add_node(dest, src);
	index = find_index(graph->array, dest);
	node->next = graph->array[index].head;
	graph->array[index].head = node;
	if (ft_strcmp(src, all->start) == 0 || ft_strcmp(dest, all->start) == 0)
		all->start_node = graph->array[index];
}

void	fill_graph(t_graph *graph, t_all *all, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < count)
	{
		add_new(graph, all->links[i], all->links[i + 1], all);
		i += 2;
		j++;
	}
}
