#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>


typedef struct		s_vertices
{
	int 			dest;
	struct s_node	*next;
}					t_vertices;

typedef struct			s_head
{
	struct s_vericies	*head;
}						t_head;

typedef struct 			s_graph
{
	int					count_vert;
	struct s_head	 	*array;
}						t_graph;

typedef struct 			s_all
{
	char				*start;
	char 				*end;
	char 				**links;
	char 				*verticies;
	int					vert;
	int					link;
	long int			ants;
}						t_all;

void	fill_all(t_all *all, char **str);
int		len_arr(char **arr);
void 	free_arr(char **arr);
void 	check(t_all *all);
int		find(char *str, char c, char b);

#endif
