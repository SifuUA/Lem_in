/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_filter2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:19:14 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 17:21:47 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		c_t(char **f_res, char *str)
{
	char	**str1;
	char	**str2;
	int		i;
	int 	j;
	int		count;

	i = 0;
	str2 = ft_strsplit(str, ' ');
	while (f_res[i])
	{
		j = 0;
		count = 0;
		str1 = ft_strsplit(f_res[i], ' ');
		while (str1[j] && str2[j])
		{
			if (ft_strcmp(str1[j], str2[j]) == 0)
				count++;
			j++;
		}
		if (count == j)
		{
			free_arr(str2);
			free_arr(str1);
			return (0);
		}
		free_arr(str1);
		i++;
	}
	if (str2)
		free_arr(str2);
	return (1);
}

int		del_contain(char **str, int size, char *current)
{
	int		i;
	int		j;
	char	**tmp;
	char	**tmp1;

	i = 0;
	j = 0;
	tmp = ft_strsplit(current, ' ');
	while (i < size)
	{
		if (ft_strcmp(current, str[i]) != 0)
		{
			tmp1 = ft_strsplit(str[i], ' ');
			if (if_contain(tmp, tmp1))
			{
				ft_bzero(str[i], ft_strlen(str[i]) - 1);
				j++;
			}
			free_arr(tmp1);
		}
		i++;
	}
	if (tmp)
		free_arr(tmp);
	return (i - j);
}

void	sort_str(char **array, int size, int i)
{
	int		j;
	char	**str1;
	char	**str2;
	char	*tmp;

	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			str1 = ft_strsplit(array[j], ' ');
			str2 = ft_strsplit(array[j + 1], ' ');
			if (len_arr(str1) > len_arr(str2))
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			free_arr(str1);
			free_arr(str2);
			j++;
		}
		i++;
	}
}

char	**record(char **str, int mem)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (mem + 1));
	while (str[i])
	{
		if (*str[i] != '\0')
			new[j++] = ft_strdup(str[i]);
		i++;
	}
	new[j] = NULL;
	return (new);
}

char	**clear(char **str, int size)
{
	int		i;
	int		mem;
	int		n_mem;
	char	**new_s;

	i = 0;
	ft_arr_putstr(str);
	sort_str(str, size, i);
	mem = len_arr(str);
	while (i < mem)
	{
		n_mem = del_contain(str, mem, str[i]);
		if (n_mem != mem)
		{
			new_s = record(str, n_mem);
			free_arr(str);
			str = new_s;
			mem = n_mem;
		}
		i++;
	}
	return (str);
}
