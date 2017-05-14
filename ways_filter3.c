#include "lem_in.h"


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
			{
				free_arr(ar_i);
				free_arr(ar_j);
				return (1);
			}
			z++;
		}
		k++;
	}
	if (ar_i)
		free_arr(ar_i);
	if (ar_j)
		free_arr(ar_j);
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

char	**check_matrix(int **matrix, int len, char **sample)
{
	int i;
	int j;
	int k;
	int one;
	char **res;

	i = 0;
	k = 0;
	res = (char **)malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		j = 0;
		one = 0;
		while (j < len)
		{
			if (matrix[i][j] == 1)
				one++;
			j++;
		}
		if (one != len || len == 1)
			res[k++] = ft_strdup(sample[i]);
		i++;
	}
	res[k] = NULL;
	return (res);
}

int 	if_contain(char **s1, char **s2)
{
	int i;
	int j;
	int len;

	i = 1;
	len = len_arr(s1);
	while (i < len - 1)
	{
		j = 1;
		while (s2[j])
		{
			if (ft_strcmp(s1[i], s2[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

