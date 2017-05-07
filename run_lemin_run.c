#include "lem_in.h"

int		len_int_ar(int *ar)
{
	int i;

	i = 0;
	while (ar[i] != STOP)
	{
		i++;
	}
		return (i);
}

int 	**get_ar(t_all *all)
{
	int 		length;
	int			i;
	int			**ar;
	long int	len;
	char		**tmp;

	i = 0;
	len = len_arr(all->res);
	ar = (int **)malloc(sizeof(int *) * len);
	ar[len] = NULL;
	while (all->res[i])
	{
		all->j = 0;
		tmp = ft_strsplit(all->res[i], ' ');
		length = len_arr(tmp);
		ar[i] = (int *)malloc(sizeof(int) * length);
		while (all->j < length)
		{
			ar[i][all->j] = 0;
			ft_putnbr(ar[i][all->j]);
			all->j++;
		}
		ar[i][all->j] = STOP;
		ft_putstr("\n");
		free_arr(tmp);
		i++;
	}
	return (ar);
}

void 		ants_on_start(int **ar, t_all *all, long int *count)
{
	int i;

	i = 0;
	while (ar[i])
	{
		ar[i][0] = 1;
		(*count)++;
		i++;
	}
}

int 	ants_in_road(int **ar)
{
	int i;
	int j;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (ar[i][j + 2] == STOP)
				break;
			if (ar[i][j] == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void 	print_way(char **res, int i, int j, long int ant)
{
	char **tmp;

	tmp = ft_strsplit(res[i], ' ');
	ft_putstr("L");
	ft_putnbr((int)ant);
	ft_putstr("-");
	ft_putstr(tmp[j + 1]);
}

void 	ants_move(int **ar, t_all *all, long int count)
{
	int i;
	int j;
	long int ant;

	i = 0;
	ant = 1;
	while (ar[i])
	{
		j = len_int_ar(ar[i]) - 2;
		j = j < 0 ? 0 : j;
		while (j >= 0)
		{
			if (ar[i][j] == 1)
			{
				ar[i][j + 1] = 1;
				ar[i][j] = 0;
				print_way(all->res, i, j, ant);
				ant++;

			}
				j--;
		}
		ft_putstr("\n");
		i++;
	}
}

void 	move(t_all *all, int **ar)
{
	long int count;
	int j;

	count = 0;
	ants_on_start(ar, all, &count);
	while (ants_in_road(ar))
	{
		ants_move(ar, all, count);
		if (all->ants > 0)
			ants_on_start(ar, all, &count);
	}
}

void	run(t_all *all)
{
	int i;
	int **ar;

	i = 0;
	ar = get_ar(all);
	move(all, ar);




}
