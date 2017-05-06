#include "lem_in.h"

int		del_contain(char **str, int size, char *current)
{
	int i;
	int j;
	char **tmp;
	char **tmp1;

	i = 0;
	j = 0;
	tmp = ft_strsplit(current, ' ');
	while (i < size)
	{
		if (ft_strcmp(current, str[i]) != 0)
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
	int 	mem;
	int		n_mem;
	char 	**new_s;

	i = 0;
	ft_arr_putstr(str);
	sort_str(str, size);
	//ft_arr_putstr(str);
	mem = len_arr(str);
	n_mem = 0;
	while (i < mem)
	{
		n_mem = del_contain(str, mem, str[i]);
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