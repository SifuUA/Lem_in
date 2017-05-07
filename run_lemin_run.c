#include "lem_in.h"

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

void 	move(t_all *all, int **ar)
{
	int i;
	int j;

	i = 0;
	ants_on_start(ar, all);
	while (ants_in_road())
	{
		ants_move();
		if (all->ants > 0)


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
