#include "lem_in.h"

void 	check(t_all *all)
{
	int i;

	i = 0;
	while (i < all->link)
	{
		if (!find(all->verticies, all->links[i]) ||
			!find(all->verticies, all->links[i + 1]))
		{
			ft_putstr("Error");
			exit(1);
		}
		i++;
	}
}

void 	control_ch(int flag, char *str)
{
	if (str[0] != '#' && flag == 0)
	{
		ft_putstr("Wrong input!");
		exit(2);
	}
}