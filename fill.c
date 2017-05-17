/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:09:42 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 15:21:11 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_vert(char *str, t_all *all)
{
	static int	i;
	char		**tmp;

	tmp = ft_strsplit(str, ' ');
	all->verticies[i++] = ft_strdup(tmp[0]);
	all->verticies[i] = NULL;
	all->flag = 1;
	free_arr(tmp);
}

void	write_link(char *str, t_all *all)
{
	char		**tmp;
	static int	j;

	tmp = ft_strsplit(str, '-');
	all->links[j++] = ft_strdup(tmp[0]);
	if (tmp[1][ft_strlen(tmp[1]) - 1] == '\r')
		tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	if (ft_strcmp(tmp[0], all->start) == 0)
	{
		if (all->dest)
			ft_strdel(&all->dest);
		all->dest = ft_strdup(tmp[1]);
	}
	else if (ft_strcmp(tmp[1], all->start) == 0)
	{
		if (all->dest)
			ft_strdel(&all->dest);
		all->dest = ft_strdup(tmp[0]);
	}
	all->links[j++] = ft_strdup(tmp[1]);
	all->flag = 1;
	free_arr(tmp);
}

void	write_start(char **str, int i, t_all *all)
{
	char **tmp;

	tmp = ft_strsplit(str[i + 1], ' ');
	if (len_arr(tmp) != 3)
	{
		ft_putstr_fd(RED"ERROR: Wrong input!\n"RESET, 2);
		exit(3);
	}
	all->start = ft_strdup(tmp[0]);
	if (tmp[2][ft_strlen(tmp[2]) - 1] == '\r')
		tmp[2][ft_strlen(tmp[2]) - 1] = '\0';
	all->flag = 1;
	free_arr(tmp);
}

void	write_end(char **str, int i, t_all *all)
{
	char **tmp;

	tmp = ft_strsplit(str[i + 1], ' ');
	all->end = ft_strdup(tmp[0]);
	all->flag = 1;
	free_arr(tmp);
}

void	fill_all(t_all *all, char **str)
{
	int		i;
	char	**tmp;
	char	**tmp1;

	i = 0;
	while (str[i])
	{
		tmp1 = NULL;
		tmp = ft_strsplit(str[i], ' ');
		all->flag = 0;
		if (!ft_strchr(str[i], '#') && !ft_strchr(str[i], '-') &&
			len_arr(tmp) == 1)
			write_ants(all, str[i]);
		else if (!ft_strchr(str[i], '-') && len_arr(tmp) == 3)
			write_vert(str[i], all);
		else if (!ft_strchr(str[i], '#') && ft_strchr(str[i], '-') &&
				len_arr((tmp1 = ft_strsplit(str[i], '-'))) == 2)
			write_link(str[i], all);
		if (ft_strstr(str[i], "##start") && str[i + 1] && str[i][7] == '\0')
			write_start(str, i, all);
		else if (ft_strstr(str[i], "##end") && str[i + 1])
			write_end(str, i, all);
		control_ch(all->flag, str[i]);
		free_tmp(tmp, tmp1, &i);
	}
}
