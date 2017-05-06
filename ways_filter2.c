#include "lem_in.h"



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
	//free_arr(sample);
	res[i] = NULL;
	return (res);
}

int		**ar_len(char **str)
{
	int i;
	int j;
	int len;
	int **count_room;
	char **tmp;

	i = 0;
	j = 0;
	len = len_arr(str);
	count_room = (int **)malloc(sizeof(int *) * len);
	while (i < len)
	{
		count_room[i] = (int *)malloc(sizeof(int) * 1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		tmp = ft_strsplit(str[i], ' ');
		count_room[i][j] = len_arr(tmp);
		free_arr(tmp);
		i++;
	}
	return (count_room);
}

int 	smallest(int num, int **ar, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ar[i][0] < num)
			return (1);
		i++;
	}
	return (0);
}

void	del_contain(char **str, char *smallest)
{
	int i;
	int j;
	char **tmp;
	char **hz;

	i = 0;
	tmp = ft_strsplit(smallest, ' ');
	while (str[i])
	{
		j = 1;
		hz = ft_strsplit(str[i], ' ');
		while (tmp[j])
		{
			if (ft_strcmp(hz[j], tmp[j]) == 0 )
			{
				ft_bzero(str[i], ft_strlen(str[i]) - 1);
				break;
			}
			j++;
		}
		i++;
	}
}

void	clear(char **str, int size)
{
	int 	i;
	int 	**arr_len;

	i = 0;
	arr_len = ar_len(str);
	while (str[i])
	{
		if (smallest(arr_len[i][0], arr_len, size) == 0)
			del_contain(str, str[i]);
		i++;
	}

}