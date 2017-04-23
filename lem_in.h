#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>


typedef struct		s_node
{
	char 			*dest;
	char 			*begin;
	struct s_node	*next;
}					t_node;

typedef struct			s_head
{
	struct s_node		*head;
	char 				*name;
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
	char 					**links;
	char 				**verticies;
	int					vert;
	int					link;
	long int			ants;
	int 				flag;
}						t_all;

void					fill_all(t_all *all, char **str);
int						len_arr(char **arr);
void 					free_arr(char **arr);
void 					check(t_all *all);
int						find(char **str, char *c);
void 					control_ch(int flag, char *str);
int						count_links(char **str);
int						count_vert(char **str);
t_graph					*creat_graph(int count_v);
t_all					*creat_struct(int count_vert, int count_links);
int 					**creat_matrix(int size);
void 					fill_matrix(int **matrix, t_all *all, int size);
#endif
