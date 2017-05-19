/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:48:37 by okres             #+#    #+#             */
/*   Updated: 2017/05/18 12:26:39 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	flag(t_all *all)
{
	if (all->print == 1)
	{
		ft_putstr("\n");
		ft_putstr(CYAN);
		ft_putstr("BEST WAYS:\n");
		ft_putstr(RESET);
		ft_putstr("*-*-*-*-*-*-*-*-*\n");
		ft_arr_putstr_mod(all->res);
		ft_putstr("*-*-*-*-*-*-*-*-*\n");
	}
}

int		hzz(int count, int j, char **str1, char **str2)
{
	if (count == j)
	{
		free_arr(str2);
		free_arr(str1);
		return (0);
	}
	free_arr(str1);
	return (1);
}

void	check(t_all *all)
{
	int i;

	i = 0;
	if (all->start == NULL || all->end == NULL)
	{
		ft_putstr(RED"ERROR: BAD START/END!\n"RESET);
		exit(5);
	}
	if (*(all->links) == NULL)
	{
		ft_putstr(RED"ERROR: BAD LINK!\n"RESET);
		exit(8);
	}
	while (i < all->link)
	{
		if (!find(all->verticies, all->links[i]) ||
			!find(all->verticies, all->links[i + 1]))
		{
			ft_putstr(RED"ERROR: WRONG ROOM!\n"RESET);
			exit(1);
		}
		i++;
	}
}

void	control_ch(int flag, char *str)
{
	if (str[0] != '#' && flag == 0)
	{
		ft_putstr_fd(RED"ERROR: Wrong input!\n"RESET, 2);
		exit(2);
	}
}

void	put_error(void)
{
	ft_putstr_fd(RED"ERROR: No possible paths!\n"RESET, 2);
	exit(4);
}
