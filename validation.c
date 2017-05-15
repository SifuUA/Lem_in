/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:48:37 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 16:49:05 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check(t_all *all)
{
	int i;

	i = 0;
	while (i < all->link)
	{
		if (!find(all->verticies, all->links[i]) ||
			!find(all->verticies, all->links[i + 1]))
		{
			ft_putstr("Error");
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