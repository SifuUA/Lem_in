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

int 	find_same(char *i, char *j)
{

}

void	fill_matrix(int **matrix, char **sample, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix[i][j] = find_same(sample[i], sample[j]);
			j++;
		}
		i++;
	}
}

void	choose_ways(t_all *all)
{
	char	**sample;
	int		**matrix;

	sample = check_ways(all->fin_res, all->start, all->end);
	matrix = (int **)malloc(sizeof(int*) * len_arr(sample));
	fill_matrix(matrix, sample, );
	ft_arr_putstr(sample);
}