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

