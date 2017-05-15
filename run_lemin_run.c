/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_lemin_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:31:22 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 16:33:00 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ants_on_start(int **ar, t_all *all, long int *count)
{
	int i;

	i = 0;
	while (ar[i] && *count < all->ants)
	{
		(*count)++;
		if ((all->ants - *count) >= all->stoper[i])
			ar[i][0] = (int)*count;
		else
		{
			ar[i][0] = 0;
			(*count)--;
		}
		i++;
	}
}

int		ants_in_road(int **ar)
{
	int i;
	int j;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j] != STOP)
		{
			if (ar[i][j] != 0)
				return (1);
			if (ar[i][j + 2] == STOP)
				break ;
			j++;
		}
		i++;
	}
	return (0);
}

void	ants_move(int **ar, t_all *all, long int count)
{
	int i;
	int j;

	i = 0;
	while (ar[i])
	{
		j = len_int_ar(ar[i]) - 2;
		j = j < 0 ? 0 : j;
		while (j >= 0)
		{
			if (ar[i][j] != 0)
			{
				ar[i][j + 1] = ar[i][j];
				ar[i][j] = 0;
				print_way(all->res, i, j, ar[i][j + 1]);
			}
			j--;
		}
		i++;
	}
	ft_putstr("\n");
}

void	move(t_all *all, int **ar)
{
	long int	count;
	int			j;

	count = 0;
	ants_on_start(ar, all, &count);
	while (ants_in_road(ar))
	{
		ants_move(ar, all, count);
		if (count < all->ants)
			ants_on_start(ar, all, &count);
	}
}

void	run(t_all *all)
{
	int		**ar;
	int		length;
	char	**tmp;
	int		i;

	i = 0;
	length = 0;
	tmp = NULL;
	ar = get_ar(all, i, length, tmp);
	stoper(all);
	move(all, ar);
	free_int_arr(ar);
}
