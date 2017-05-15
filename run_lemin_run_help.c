/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_lemin_run_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:33:15 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 16:34:49 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_int_arr(int **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr[i]);
	arr[i] = NULL;
	free(arr);
}

int		len_int_ar(int *ar)
{
	int	i;

	i = 0;
	while (ar[i] != STOP)
	{
		i++;
	}
	return (i);
}

void	stoper(t_all *all)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all->res[i])
	{
		tmp = ft_strsplit(all->res[i], ' ');
		all->storage[i] = len_arr(tmp) - 1;
		all->stoper[j] = all->storage[i] - all->storage[0] + i - 1;
		i++;
		j++;
		if (tmp)
			free_arr(tmp);
	}
}

void	get_ar_help(int **ar, t_all *all, int len)
{
	ar = (int **)malloc(sizeof(int *) * len + 1);
	all->stoper = (int *)malloc(sizeof(int ) * len + 1);
	all->storage = (int *)malloc(sizeof(int ) * len + 1);
	ar[len] = NULL;
}

int		**get_ar(t_all *all, int i, int length, char **tmp)
{
	int			**ar;
	long int	len;

	len = len_arr(all->res);
	get_ar_help(ar, all, len);
	while (all->res[i])
	{
		all->j = 0;
		tmp = ft_strsplit(all->res[i], ' ');
		length = len_arr(tmp);
		ar[i] = (int *)malloc(sizeof(int) * length + 1);
		while (all->j < length)
		{
			ar[i][all->j] = 0;
			ft_putnbr(ar[i][all->j]);
			all->j++;
		}
		ar[i][all->j] = STOP;
		ft_putstr("\n");
		if (tmp)
			free_arr(tmp);
		i++;
	}
	ar[i] = NULL;
	return (ar);
}
