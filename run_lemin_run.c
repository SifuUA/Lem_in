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
	ar = (int **)malloc(sizeof(int *) * len + 1);
	ar[len] = NULL;
	while (all->res[i])
	{
		all->j = 0;
		tmp = ft_strsplit(all->res[i], ' ');
		length = len_arr(tmp);
		ar[i] = (int *)malloc(sizeof(int) * length + 1);
		while (all->j < length)
		{
			ar[i][all->j] = 0;
			ft_putnbr(ar[i][all->j]);
			all->j++;
		}
		ar[i][all->j] = STOP;
		ft_putstr("\n");
		//free_arr(tmp);
		i++;
	}
	ar[i] = NULL;
	return (ar);
}

void 		 ants_on_start(int **ar, t_all *all, long int *count)
{
	int i;

	i = 0;
	while (ar[i] && *count < all->ants)
	{
		(*count)++;
		ar[i][0] = (int)*count;
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
		while (ar[i][j] != STOP)
		{
			if (ar[i][j] != 0)
				return (1);
			if (ar[i][j + 2] == STOP)
				break;

			j++;
		}
		i++;
	}
	return (0);
}

void 	print_way(char **res, int i, int j, int ant )
{
	char **tmp;

	tmp = ft_strsplit(res[i], ' ');
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(tmp[j + 1]);
	ft_putstr(" ");
}

void 	ants_move(int **ar, t_all *all, long int count)
{
	int i;
	int j;

	i = 0;
	while (ar[i])
	{
		j = len_int_ar(ar[i]) - 2;
		j = j < 0 ? 0 : j;
		while (j >= 0)
		{
			if (ar[i][j] != 0)
			{
				ar[i][j + 1] = ar[i][j];
				ar[i][j] = 0;
				print_way(all->res, i, j, ar[i][j + 1]);

			}
			j--;
		}
		i++;
	}
	ft_putstr("\n");
}

void 	zero_start(int **ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		ar[i][0] = 0;
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
		if (count < all->ants)
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
