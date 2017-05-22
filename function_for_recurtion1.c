/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_recurtion1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:51:23 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 15:53:21 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				check_res(char *res, char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	if (res)
		tmp = ft_strsplit(res, ' ');
	while (tmp && tmp[i])
	{
		if (ft_strcmp(tmp[i], str) == 0)
		{
			free_arr(tmp);
			return (1);
		}
		i++;
	}
	if (tmp)
		free_arr(tmp);
	return (0);
}

struct s_node	*find_node(t_graph *graph, char *dest, char *begin)
{
	int		i;
	t_node	*tmp;

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

char			*get_to(char *str, char *to)
{
	char	*hz;
	char	**tmp;
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	tmp = ft_strsplit(str, ' ');
	while (tmp[i] && ft_strcmp(tmp[i], to) != 0)
	{
		hz = ft_strjoin_mod2(res, tmp[i]);
		if (res)
			ft_strdel(&res);
		res = ft_strjoin(hz, " ");
		ft_strdel(&hz);
		i++;
	}
	hz = ft_strjoin(res, tmp[i]);
	ft_strdel(&res);
	res = ft_strjoin(hz, " ");
	ft_strdel(&hz);
	free_arr(tmp);
	return (res);
}
