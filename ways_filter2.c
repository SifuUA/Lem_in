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

int		del_contain(char **str, int size)
{
	int i;
	int j;
	char **tmp;
	char **tmp1;

	i = 0;
	j = 0;
	tmp = ft_strsplit(*str, ' ');
	while (i < size)
	{
		if (ft_strcmp(*str, str[i]) != 0)
		{
			tmp1 = ft_strsplit(str[i], ' ');
			if (if_contain(tmp, tmp1))
			{
				ft_bzero(str[i], ft_strlen(str[i]) - 1);
				j++;
			}
			free_arr(tmp1);
		}
		i++;
	}
	return (i - j);
}

void	sort_str(char **array, int size)
{
	int i;
	int j;
	char **str1;
	char **str2;
	char *tmp;

	i = 0;
	tmp = NULL;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			str1 = ft_strsplit(array[j], ' ');
			str2 = ft_strsplit(array[j + 1], ' ');
			if (len_arr(str1) > len_arr(str2))
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			free_arr(str1);
			free_arr(str2);
			j++;
		}
		i++;
	}
}

char	**record(char **str, int  mem)
{
	int i;
	int j;
	char **new;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (mem + 1));
	while (str[i])
	{
		if (*str[i] != '\0')
			new[j++] = ft_strdup(str[i]);
		i++;
	}
	new[j] = NULL;
	return (new);
}

char	**clear(char **str, int size)
{
	int 	i;
	int 	**arrr_len;
	int 	mem;
	int		n_mem;
	char 	**new_s;

	i = 0;
	arrr_len = ar_len(str);
	ft_arr_putstr(str);
	sort_str(str, size);
	ft_putstr("**********************\n");
	//ft_arr_putstr(str);
	mem = len_arr(str);
	n_mem = 0;
	while (i < mem)
	{
		n_mem = del_contain(str, mem);
		if (n_mem != mem)
		{
			new_s = record(str, n_mem);
			free_arr(str);
			str = new_s;
			mem = n_mem;
		}
		i++;
	}
	return (str);
}