/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:57:48 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 15:00:02 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_ants(t_all *all, char *str)
{
	all->ants = ft_atoi(str);
	all->flag = 1;
}

t_graph	*creat_graph(long int count_v)
{
	t_graph	*graph;
	int		i;

	i = 0;
	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->count_vert = count_v;
	graph->array = (t_head *)malloc(sizeof(t_head) * count_v + 1);
	while (i <= count_v)
	{
		graph->array[i].head = NULL;
		i++;
	}
	return (graph);
}

t_all	*creat_struct(long int count_vert, int count_links)
{
	t_all		*all;
	long int	i;

	i = 0;
	all = (t_all *)malloc(sizeof(t_all));
	all->start = NULL;
	all->end = NULL;
	all->dest = NULL;
	all->verticies = (char **)malloc(sizeof(char*) * count_vert + 1);
	all->verticies[count_vert + 1] = NULL;
	all->links = (char **)malloc(sizeof(char*) * (count_links * 2) + 1);
	all->links[(count_links * 2)] = NULL;
	all->link = count_links;
	all->res = (char **)malloc(sizeof(char*) * count_links * 10);
	all->res[count_links * 10] = NULL;
	all->fin_res = (char **)malloc(sizeof(char*) * count_links * 10);
	all->fin_res[count_links * 10] = NULL;
	all->i = 0;
	all->r_rec = 0;
	all->j = 0;
	all->k = 0;
	all->tmp = NULL;
	return (all);
}
