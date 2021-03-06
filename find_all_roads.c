/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_roads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:11:08 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 15:37:40 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_in_while(t_all *all, t_graph *graph, t_node **node, t_node **tmp)
{
	char **p;

	p = ft_strsplit(all->res[all->i], ' ');
	if (all->flag != 3)
		*tmp = graph->array[find_index(graph->array, (*node)->dest)].head;
	else
	{
		*tmp = *node;
		all->flag = 0;
		if (all->res[all->i])
			ft_strdel(&(all->res[all->i]));
		all->res[all->i] = clear_other(p, (*node)->begin);
	}
	if (p)
		free_arr(p);
	(*node)->mark = 1;
}

void	aft_r(t_node **node, t_all *all)
{
	char *tmp;

	*node = all->start_save->next;
	all->flag = 0;
	all->r_rec = 0;
	ft_strdel(&(all->res[all->i]));
	all->res[all->i] = all->start_save->begin;
	tmp = ft_strjoin_mod2(all->res[all->i], " ");
	all->res[all->i] = tmp;
	tmp = ft_strjoin_mod2(all->res[all->i], (*node)->dest);
	ft_strdel(&(all->res[all->i]));
	all->res[all->i] = tmp;
	all->start_save = all->start_save->next;
}

void	f_check_help(t_all *all, t_node *node)
{
	char	*tmp;

	tmp = ft_strjoin_mod2(all->res[all->i], " ");
	ft_strdel(&(all->res[all->i]));
	all->res[all->i] = tmp;
	tmp = ft_strjoin_mod2(all->res[all->i], node->dest);
	ft_strdel(&(all->res[all->i]));
	all->res[all->i] = tmp;
	all->r_rec = 0;
}

int		f_check(t_all *all, t_node *node, int dep)
{
	if (all->res[all->i] && check_res(all->res[all->i], node->dest) &&
		ft_strcmp(node->dest, all->end) != 0)
	{
		return (node->mark = 1);
	}
	else
	{
		if (all->r_rec == 1)
		{
			all->i++;
			all->res[all->i] = get_to(all->res[all->i - 1], node->begin);
		}
		f_check_help(all, node);
	}
	if (ft_strcmp(node->dest, all->end) == 0)
	{
		all->r_rec = 1;
		all->fin_res[all->k++] = ft_strdup(all->res[all->i]);
		if (dep == 0 && ft_strcmp(node->dest, all->end) == 0 &&
				node->next != NULL)
			return (0);
		else
			return (1);
	}
	return (0);
}

void	rec_f(t_all *all, t_graph *graph, t_node *node, int dep)
{
	t_node	*tmp;

	if (all->j++ == 0)
	{
		all->ss = graph->array[find_index(graph->array, node->dest)].head;
		all->start_save = node;
	}
	if (f_check(all, node, dep) == 1)
		return ;
	while (node)
	{
		check_in_while(all, graph, &node, &tmp);
		rec_f(all, graph, tmp, dep + 1);
		node = tmp->next;
		all->flag = 3;
		if (node == NULL &&
				all->start_save->next && dep == 0)
			aft_r(&node, all);
		else if (node == NULL && ft_strcmp(tmp->begin, all->end) == 0)
			all->fin_res[all->k++] = ft_strdup(all->res[all->i]);
	}
}
