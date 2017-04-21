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

void	find_vert(t_all *all, char **str)
{
	int i;
	char **tmp;

	i = 0;
	while (str[i])
	{
		//ft_putstr(str[i]);
		//ft_putstr("\n");
		ft_strsplit(str[i], ' ');
		//int tmp = len_arr(ft_strsplit(str[i], ' '));
		//ft_putnbr(tmp);
		i++;
	}
}

