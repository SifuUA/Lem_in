/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:53:18 by okres             #+#    #+#             */
/*   Updated: 2017/05/18 15:15:27 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_int_arr_m(int **arr, int high)
{
	int i;

	i = 0;
	while (i < high)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

int		count_start_end(char *ar, char *str)
{
	int		i;
	int		count;
	char	**tmp;

	i = 0;
	count = 0;
	tmp = ft_strsplit(ar, ' ');
	while (tmp[i])
	{
		if (ft_strcmp(tmp[i], str) == 0)
			count++;
		i++;
	}
	free_arr(tmp);
	return (count);
}

char	**check_ways(char **res, char *start, char *end)
{
	int		i;
	int		j;
	char	**f_res;
	int		len;

	i = 0;
	j = 0;
	len = len_arr(res);
	f_res = (char **)malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		f_res[i] = NULL;
		i++;
	}
	i = 0;
	while (res[i])
	{
		if (res[i] && count_start_end(res[i], start) == 1 &&
			count_start_end(res[i], end) == 1 && c_t(f_res, res[i], i))
			f_res[j++] = ft_strdup(res[i]);
		i++;
	}
	f_res[j] = NULL;
	return (f_res);
}

void	choose_ways_pre(t_all *all)
{
	int		i;
	char	**sample;
	int		**matrix;

	i = 0;
	sample = NULL;
	matrix = NULL;
	choose_ways(all, i, sample, matrix);
}

void	choose_ways(t_all *all, int i, char **sample, int **matrix)
{
	char	**tmp;
	int		len;

	i = 0;
	sample = check_ways(all->fin_res, all->start, all->end);
	len = len_arr(sample);
	matrix = (int **)malloc(sizeof(int *) * len + 1);
	matrix[len + 1] = 0;
	while (i < len)
	{
		matrix[i] = (int *)malloc(sizeof(int) * len + 1);
		matrix[i++][len] = 0;
	}
	fill_matrix(matrix, sample, len, all);
	sample[0] = sample[0] == NULL ? ft_strdup(all->fin_res[0]) : sample[0];
	tmp = check_matrix(matrix, len, sample, all);
	free_arr(sample);
	len = len_arr(tmp);
	free_arr(all->res);
	all->res = clear(tmp, len, all);
	free_int_arr_m(matrix, i);
	flag(all);
	run(all);
	free_arr(all->res);
	free_arr(all->fin_res);
}
