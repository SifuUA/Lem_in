/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:43:50 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 17:46:10 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**read_and_write(void)
{
	char	*line;
	char	**save;
	int		i;

	i = 0;
	save = (char **)malloc(sizeof(char*) * 10000);
	while (get_next_line(0, &line) && *line != 0)
	{
		save[i++] = line;
		ft_putstr(line);
		ft_putstr("\n");
	}
	ft_strdel(&line);
	return (save);
}

void	all_clear(t_all *all)
{
	if (all->verticies)
		free_arr(all->verticies);
	all->verticies = NULL;
	if (all->links)
		free_arr(all->links);
	all->links = NULL;
	all->ss = NULL;
	ft_strdel(&(all->start));
	ft_strdel(&(all->end));
	ft_strdel(&(all->dest));
	if (all->tmp)
		free(all->tmp);
	all->tmp = NULL;
	if (all->stoper)
		free(all->stoper);
	all->stoper = NULL;
	if (all->storage)
		free(all->storage);
	free(all);
}

void	mem_clear(char **save, t_graph *graph)
{
	long int	i;
	t_node		*node;
	t_node		*tmp_node;

	i = 0;
	if (save)
		free_arr(save);
	while (graph->array[i].head)
	{
		node = graph->array[i].head;
		while (node)
		{
			ft_strdel(&(node->begin));
			ft_strdel(&node->dest);
			tmp_node = node->next;
			free(node);
			node = tmp_node;
		}
		graph->array[i].head = NULL;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_graph		*graph;
	t_all		*all;
	t_node		*node_start;
	char		**save;
	long int	count_v;

	save = read_and_write();
	count_v = count_vert(save);
	all = creat_struct(count_v, count_links(save));
	fill_all(all, save);
	check(all);
	graph = creat_graph(count_v);
	fill_graph(graph, all, count_links(save));
	node_start = find_node(graph, all->dest, all->start);
	all->res[0] = ft_strdup(node_start->begin);
	rec_f(all, graph, node_start, 0);
	all->res[all->i + 1] = NULL;
	all->fin_res[all->k] = NULL;
	if (all->k == 0)
		put_error();
	choose_ways_pre(all);
	all_clear(all);
	mem_clear(save, graph);
}
