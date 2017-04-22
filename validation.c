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

void	fill_all(t_all *all, char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], '-'))
		{
			if (ft_strstr(str[i], "##start") && str[i + 1])
				all->start = ft_strsplit(str[++i], ' ');
			else if (ft_strstr(str[i], "##end"))
				all->start = ft_strsplit(str[++i], ' ');
			//tmp = ft_strsplit(str[i], ' ');
		}
		//ft_arr_putstr(tmp);
		//ft_putstr("**********************\n");
		//int len = len_arr(tmp);
		//ft_putnbr(len);
		i++;
	}
}

