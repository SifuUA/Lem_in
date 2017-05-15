/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_filter3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:24:30 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 17:26:50 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mem_cl(char **ar_i, char **ar_j)
{
	free_arr(ar_i);
	free_arr(ar_j);
}

int		find_same(char *i, char *j, t_all *all)
{
	char	**ar_i;
	char	**ar_j;

	all->k = 1;
	ar_i = ft_strsplit(i, ' ');
	ar_j = ft_strsplit(j, ' ');
	while (ar_i[all->k] && ft_strcmp(ar_i[all->k], all->end) != 0)
	{
		all->z = 1;
		while (ar_j && ar_j[all->z])
		{
			if (ft_strcmp(ar_i[all->k], ar_j[all->z]) == 0)
			{
				mem_cl(ar_i, ar_j);
				return (1);
			}
			all->z++;
		}
		all->k++;
	}
	if (ar_i)
		free_arr(ar_i);
	if (ar_j)
		free_arr(ar_j);
	return (0);
}

void	fill_matrix(int **matrix, char **sample, int size, t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = find_same(sample[i], sample[j], all);
			j++;
		}
		i++;
	}
}

char	**check_matrix(int **matrix, int len, char **sample)
{
	int		i;
	int		j;
	int		k;
	int		one;
	char	**res;

	i = 0;
	k = 0;
	res = (char **)malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		j = 0;
		one = 0;
		while (j < len)
		{
			if (matrix[i][j] == 1)
				one++;
			j++;
		}
		if (one != len || len == 1)
			res[k++] = ft_strdup(sample[i]);
		i++;
	}
	res[k] = NULL;
	return (res);
}

int		if_contain(char **s1, char **s2)
{
	int i;
	int j;
	int len;

	i = 1;
	len = len_arr(s1);
	while (i < len - 1)
	{
		j = 1;
		while (s2[j])
		{
			if (ft_strcmp(s1[i], s2[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
