/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:19:45 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 16:20:48 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		len_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		i++;
	}
	ft_strdel(&(arr[i]));
	free(arr);
}

int		find(char **str, char *c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], c) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		count_links(char **str)
{
	int		i;
	int		count;
	char	**tmp;

	i = 0;
	count = 0;
	while (str[i])
	{
		tmp = ft_strsplit(str[i], '-');
		if (ft_strchr(str[i], '-') && !ft_strchr(str[i], '#') &&
			len_arr(tmp) == 2)
			count++;
		i++;
		if (tmp)
			free_arr(tmp);
	}
	return (count);
}

int		count_vert(char **str)
{
	int		i;
	int		count;
	char	**tmp;

	i = 0;
	count = 0;
	while (str[i])
	{
		tmp = ft_strsplit(str[i], ' ');
		if (!ft_strchr(str[i], '-') && !ft_strchr(str[i], '#') &&
			len_arr(tmp) == 3)
			count++;
		i++;
		if (tmp)
		{
			free_arr(tmp);
		}
	}
	return (count);
}
