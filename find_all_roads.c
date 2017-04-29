#include "lem_in.h"

int 	check_res_mod(char **res, char *str)
{
	int i;
	int j;
	char **tmp;

	i = 0;
	j = 0;
	while (res && res[i])
	{
		tmp = ft_strsplit(res[i], ' ');
		while (tmp[j])
		{
			if (ft_strcmp(tmp[j], str) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}

int 	check_res(char *res, char *str)
{
	int i;
	char **tmp;

	i = 0;
	tmp = ft_strsplit(res, ' ');

	while (tmp && tmp[i])
	{
		if (ft_strcmp(tmp[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

struct s_node * find_node(t_graph *graph, char *dest, char *begin)
{
	int i;
	t_node *tmp;

	i = 0;
	while (i < graph->count_vert)
	{
		tmp = graph->array[i].head;
		while (tmp)
		{
			if (ft_strcmp(tmp->dest, dest) == 0
				&& ft_strcmp(tmp->begin, begin) == 0)
				return (graph->array[i].head);
			tmp = tmp->next;
		}
		i++;
	}
	return (NULL);
}

void	clear_mark(t_graph *graph)
{
	t_node *ptr;

	int i;

	i = 0;
	while (i < graph->count_vert)
	{
		ptr = graph->array[i].head;
		while (ptr) {
			ptr->mark = 0;
			ptr = ptr->next;
		}
		i++;
	}
}

int 	get_index(char **str, char *st)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], st) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	del_last(char *str)
{
	size_t len;

	len = ft_strlen(str) - 1;
	if (str[len] == ' ')
		str[len] = '\0';
	while (*str && str[len] != ' ')
	{
		str[len] = '\0';
		len--;
	}
}

void	rec_f(t_all *all, t_graph *graph, t_node *node, t_node *start)
{
	t_node *tmp;

	if (node->mark == 1)
			return ;// якщо в моєму 2вимірному масиві є така кімната і це не кінець то return
	else
	{
		all->res[all->i] = ft_strjoin(all->res[all->i], " ");// тут записую через ' ' кімнати в i-ту строку 2вимірного масива
		all->res[all->i] = ft_strjoin(all->res[all->i], node->dest);
		all->j = 0;
		node->mark = 1;
		tmp = find_node(graph, node->begin, node->dest);
		while (ft_strcmp(tmp->dest, node->begin) != 0 || ft_strcmp(tmp->begin, node->dest))
			tmp= tmp->next;
		tmp->mark = 1;


	}
	if (ft_strcmp(node->dest, all->end) == 0)
	{
		all->i++;
		all->j = 7;
		all->res[all->i] = ft_strdup(all->res[all->i - 1]);
		return ;//якщо дійшов до кінця повертаюсь на крок назад
	}
	while (node)
	{
		//node->mark = 1;
		if (all->flag != 3)// перевірка чи рекурсія повертається назад
		{
			tmp = graph->array[find_index(graph->array, node->dest)].head;// так я знаходжу саме той вузол з мого масива листів на який вказує лінк
		}
		else
		{
			tmp = node;
			all->flag = 0;
			if (all->j == 7 && ft_strstr(all->res[all->i], node->dest))
			{
				del_last(all->res[all->i]);// видаленння останньоі кімнати з строки
			}
		}
		rec_f(all, graph, tmp, start);// рекурсія
		node = tmp->next;
		all->flag = 3;
	}
}