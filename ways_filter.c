#include "lem_in.h"

void 	free_int_arr_m(int **arr, int width, int high)
{
	int i;

	i = 0;
	while (i < high)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

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
	f_res = (char **)malloc(sizeof(char *) * len_arr(res) + 1);
	while (res[i])
	{
		if (res[i] && count_start_end(res[i], start) == 1 &&
				count_start_end(res[i], end) == 1)
			f_res[j++] = ft_strdup(res[i]);
		i++;
	}
	f_res[j] = NULL;
	return (f_res);
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
	matrix = (int **)malloc(sizeof(int *) * len + 1);
	matrix[len + 1] = 0;
	while (i < len)
	{
		matrix[i] = (int *)malloc(sizeof(int) * len + 1);
		matrix[i][len + 1] = 0;
		i++;
	}
	fill_matrix(matrix, sample, len, all);
	tmp = check_matrix(matrix, len, sample);
	free_arr(sample);
	sample = NULL;
	len = len_arr(tmp);
	free_arr(all->res);
	//free_arr(all->fin_res);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	all->res = clear(tmp, len);
	free_arr(tmp);//???
	tmp = NULL;
	free_int_arr_m(matrix, len, i);//переделать с границами!!!
	ft_putstr("**********************\n");
	ft_arr_putstr(all->res);
	run(all);
}