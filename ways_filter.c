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
	//free_arr(tmp);
	return (count);
}

int		c_t(char **f_res, char *str)
{
	int i;

	i = 0;
	while (f_res[i])
	{
		if (ft_strcmp(f_res[i], str) == 0)
			return (0);
		i++;
	}
	return (1);
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
		if (res[i] && count_start_end(res[i], start) == 1 &&
				count_start_end(res[i], end) == 1 && c_t(f_res, res[i]))
			f_res[j++] = res[i];
		//else
		//	free(res[i]);
		i++;
	}
	f_res[j] = NULL;
	//free_arr(res);
	//ft_arr_putstr(f_res);
	return (f_res);
}

int 	find_same(char *i, char *j, t_all *all)
{
	int 	k;
	int 	z;
	char 	**ar_i;
	char 	**ar_j;

	k = 1;
	ar_i = ft_strsplit(i, ' ');
	ar_j = ft_strsplit(j, ' ');
	while (ar_i[k] && ft_strcmp(ar_i[k], all->end ) != 0)
	{
		z = 1;
		while (ar_j && ar_j[z])
		{
			if (ft_strcmp(ar_i[k], ar_j[z]) == 0)
				return (1);
			z++;
		}
		k++;
	}
	return (0);
}

void	fill_matrix(int **matrix, char **sample, int size, t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = find_same(sample[i], sample[j], all);
			ft_putnbr(matrix[i][j]);

			j++;

		}
		ft_putstr("\n");
		i++;
	}
}


void	choose_ways(t_all *all)
{
	int 	i;
	char	**sample;
	int		**matrix;
	char 	**tmp;
	int		len;

	i = 0;
	sample = check_ways(all->fin_res, all->start, all->end);
	len = len_arr(sample);
	matrix = (int **)malloc(sizeof(int*) * len);
	while (i < len)
	{
		matrix[i] = (int *)malloc(sizeof(int) * len);
		i++;
	}
	//ft_arr_putstr(sample);
	fill_matrix(matrix, sample, len, all);
	tmp = check_matrix(matrix, len, sample);
	//ft_arr_putstr(tmp);
	len = len_arr(tmp);
	char **aaa = clear(tmp, len);
	ft_arr_putstr(aaa);
}