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
