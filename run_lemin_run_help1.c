/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_lemin_run_help1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:47:53 by okres             #+#    #+#             */
/*   Updated: 2017/05/18 15:16:08 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_way(char **res, int i, int j, int ant)
{
	char	**tmp;

	tmp = ft_strsplit(res[i], ' ');
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(tmp[j + 1]);
	ft_putstr(" ");
	free_arr(tmp);
}

void	pr_er(void)
{
	ft_putstr(RED"ERROR: BAD START/END!\n"RESET);
	exit(6);
}
