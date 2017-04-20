#include "lem_in.h"

t_list creat_list()
{
	t_list *tmp;
	tmp = (t_list *)malloc(sizeof(t_list));

}

int		main(int argc, char **argv)
{
	char *line;

	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");}
}

