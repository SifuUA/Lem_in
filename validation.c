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
	if (ft_strstr(str[*i], "##start"))
	{
		tmp = ft_strsplit(str[++*i], ' ');
		if (len_arr(tmp) == 3)
		{
			all->start = ft_strsplit(str[*i], ' ');
			all->verticies[j++] = all->start[0][0];
		}
		else
			strerror(1);
	}
	else if (ft_strstr(str[*i], "##end") && str[*i + 1])
	{
		all->end = ft_strsplit(str[++*i], ' ');
		all->verticies[j++] = all->end[0][0];
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

