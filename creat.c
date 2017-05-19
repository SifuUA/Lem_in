/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:57:48 by okres             #+#    #+#             */
/*   Updated: 2017/05/18 15:15:42 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_all(char **str)
{
	ft_putstr("\n");
	ft_putstr(YELLOW);
	ft_putstr("ALL WAYS:\n");
	ft_putstr(RESET);
	ft_putstr("*-*-*-*-*-*-*-*-*\n");
	ft_putstr(MAGENTA);
	ft_arr_putstr(str);
	ft_putstr(RESET);
	ft_putstr("*-*-*-*-*-*-*-*-*\n");
	ft_putstr(RESET);
}

void	ft_arr_putstr_mod(char **str)
{
	int i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			ft_putstr(GREEN);
			ft_putendl(str[i]);
			ft_putstr(RESET);
			i++;
		}
	}
}

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

	all = (t_all *)malloc(sizeof(t_all));
	all->start = NULL;
	all->end = NULL;
	all->dest = NULL;
	all->verticies = (char **)malloc(sizeof(char*) * count_vert + 1);
	all->verticies[count_vert + 1] = NULL;
	all->links = (char **)malloc(sizeof(char*) * (count_links * 2) + 1);
	all->links[(count_links * 2)] = NULL;
	all->link = count_links;
	all->res = (char **)malloc(sizeof(char*) * count_links * 1000);
	all->res[count_links * 1000] = NULL;
	all->fin_res = (char **)malloc(sizeof(char*) * count_links * 1000);
	all->fin_res[count_links * 1000] = NULL;
	all->i = 0;
	all->r_rec = 0;
	all->j = 0;
	all->k = 0;
	all->tmp = NULL;// almost fin
	return (all);
}
