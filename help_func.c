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

int		find(char *str, char c, char b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == b)
			return (1);
		i++;
	}
	return (0);
}