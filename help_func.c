#include "lem_in.h"

int		len_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		i++;
	}
	return (i);
}

void 	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);// питання з приводу фрішення???
		i++;
	}
	free(arr);
}

int		find(char **str, char *c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], c) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		count_links(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strchr(str[i], '-') && !ft_strchr(str[i], '#') &&
			len_arr(ft_strsplit(str[i], '-')) == 2)
			count++;
		i++;
	}
	return (count);
}

int		count_vert(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], '-') && !ft_strchr(str[i], '#') &&
			len_arr(ft_strsplit(str[i], ' ')) == 3)
			count++;
		i++;
	}
	return (count);
}