#include "lem_in.h"

int		count_start_end(char *ar, char *str)
{
	int i;
	int count;
	char **tmp;

	i = 0;
	count = 0;
	tmp = ft_strsplit(ar, ' ');
	while (tmp[i])
	{
		if (ft_strcmp(tmp[i], str) == 0)
			count++;
		i++;
	}
	free_arr(tmp);
	return (count);
}

char	**check_ways(char **res, char *start, char *end)
{
	int		i;
	int		j;
	char	**f_res;

	i = 0;
	j = 0;
	f_res = (char **)malloc(sizeof(char *) * len_arr(res));
	while (res[i])
	{
		if (count_start_end(res[i], start) == 1 &&
				count_start_end(res[i], end) == 1)
			f_res[j++] = ft_strdup(res[i]);
		i++;
	}
	free_arr(res);
	return (f_res);
}

void	choose_ways(t_all *all)
{
	char	**tmp;
	int		**mat
	tmp = check_ways(all->fin_res, all->start, all->end);
	ft_arr_putstr(tmp);
}