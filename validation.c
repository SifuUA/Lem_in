#include <stdio.h>
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

void 	find_s_e_v(char **str, t_all *all, int *i)
{
	int 	j;
	char 	**tmp;

	j = 0;
	all->verticies = malloc(sizeof(t_all *) * 1000);
	if (ft_strstr(str[*i], "##start"))
	{
		tmp = ft_strsplit(str[++*i], ' ');
		if (len_arr(tmp) == 3)
		{
			all->start = tmp[0];
			all->verticies[j++] = all->start;
			free(tmp);
		}
	}
	else if (ft_strstr(str[*i], "##end") && str[*i + 1])
	{
		tmp = ft_strsplit(str[++*i], ' ');
		all->end = tmp[0];
		all->verticies[j++] = all->end;
		free(tmp);
	}
	else if (len_arr(ft_strsplit(str[*i], ' ')) == 3)
	{
		tmp = ft_strsplit(str[*i], ' ');
		all->verticies[j] = tmp[0][0];
	}

}

void	fill_all(t_all *all, char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], '-'))
		{
			find_s_e_v(str, all, &i);
		}
		//ft_arr_putstr(tmp);
		//int len = len_arr(tmp);
		//ft_putnbr(len);
		i++;
	}
}

