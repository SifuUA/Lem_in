#include "lem_in.h"

void 	write_vert(char *str, t_all *all)
{
	static int i;

	all->verticies[i++] = *str;
}

void	fill_all(t_all *all, char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], '#') && !ft_strchr(str[i], '-')&&
				len_arr(ft_strsplit(str[i], ' ')) == 1)
		{
			all->ants = ft_atoi(str[i]);
		}
		if (!ft_strchr(str[i], '-') &&
				len_arr(ft_strsplit(str[i], ' ')) == 3)
			write_vert(str[i], all);
		//ft_arr_putstr(tmp);
		//int len = len_arr(tmp);
		//ft_putnbr(len);
		i++;
	}
}

