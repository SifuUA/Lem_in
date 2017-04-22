#include "lem_in.h"

void 	write_vert(char *str, t_all *all)
{
	static int i;

	all->verticies[i++] = *str;
}

void 	write_link(char *str, t_all *all)
{
	char 		**tmp;
	static int j;

	tmp = ft_strsplit(str, '-');
	all->links[j++] = tmp[0];
	all->links[j++] = tmp[1];
	free_arr(tmp);
}

void 	write_start(char **str, int i, t_all * all)
{
	char **tmp;

	tmp = ft_strsplit(str[i + 1], ' ');
	all->start = tmp[0];
	free_arr(tmp);
}

void 	write_end(char **str, int i, t_all * all)
{
	char **tmp;

	tmp = ft_strsplit(str[i + 1], ' ');
	all->end = tmp[0];
	free_arr(tmp);
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
			all->ants = ft_atoi(str[i]);
		else if (!ft_strchr(str[i], '-') &&
				len_arr(ft_strsplit(str[i], ' ')) == 3)
			write_vert(str[i], all);
		else if (!ft_strchr(str[i], '#') && ft_strchr(str[i], '-')
				 && len_arr(ft_strsplit(str[i], '-')) == 2)
			write_link(str[i], all);
		if (ft_strstr(str[i], "##start") && str[i + 1])
			write_start(str, i, all);
		else if (ft_strstr(str[i], "##end") && str[i + 1])
			write_end(str, i, all);
		i++;
	}
}

void 	check(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < all->link)
	{
		j = 0;
		if (!find(all->verticies, all->links[i][j],
				all->links[i][j + 1]))
		{
			ft_putstr("Error");
			exit(2);
		}
		i++;
	}
}