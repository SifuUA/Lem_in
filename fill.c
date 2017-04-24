#include "lem_in.h"

void 	write_vert(char *str, t_all *all)
{
	static int 	i;
	char 		**tmp;

	tmp = ft_strsplit(str, ' ');
	all->verticies[i++] = tmp[0];
	all->flag = 1;
}

void 	write_link(char *str, t_all *all)
{
	char 		**tmp;
	static int j;

	tmp = ft_strsplit(str, '-');
	all->links[j++] = tmp[0];
	if (tmp[1][ft_strlen(tmp[1]) - 1] == '\r')
		tmp[1][ft_strlen(tmp[1]) - 1]  = '\0';
	all->links[j++] = tmp[1];
	all->flag = 1;
	//free_arr(tmp);
}

void 	write_start(char **str, int i, t_all * all)
{
	char **tmp;

	tmp = ft_strsplit(str[i + 1], ' ');
	if (len_arr(tmp) != 3)
	{
		ft_putstr("Wrong input!");
		exit(2);
	}
	all->start = tmp[0];
	all->flag = 1;
	free_arr(tmp);
}

void 	write_end(char **str, int i, t_all * all)
{
	char **tmp;

	tmp = ft_strsplit(str[i + 1], ' ');
	all->end = tmp[0];
	all->flag = 1;
	free_arr(tmp);
}

void	fill_all(t_all *all, char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		all->flag = 0;
		if (!ft_strchr(str[i], '#') && !ft_strchr(str[i], '-') &&
				len_arr(ft_strsplit(str[i], ' ')) == 1)
		{
			all->ants = ft_atoi(str[i]);
			all->flag = 1;
		}
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
		control_ch(all->flag, str[i]);
		i++;
	}
}