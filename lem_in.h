#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>


typedef struct		s_node
{
	int 			mark;
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
	long int			count_vert;
	long int			count_links;
	struct s_head	 	*array;
}						t_graph;

typedef struct			s_llist
{
	struct	s_head		head;
}						t_llist;

typedef struct 			s_all
{
	char				*start;
	struct s_head 		start_node;
	char 				*end;
	char 				**links;
	char 				**verticies;
	int					link;
	long int			ants;
	int 				flag;
	char 				**res;
	int 				i;
	char				*dest;
	int 				j;
	int 				k;
	int 				r_rec;
	char 				**fin_res;
	t_node				*ss;
	t_node				*start_save;
	t_node				*tmp;
}						t_all;

void					fill_all(t_all *all, char **str);
int						len_arr(char **arr);
void 					free_arr(char **arr);
void 					check(t_all *all);
int						find(char **str, char *c);
int						find_index(t_head *arr, char *str);
void 					control_ch(int flag, char *str);
int						count_links(char **str);
int						count_vert(char **str);
t_graph					*creat_graph(int count_v);
t_all					*creat_struct(int count_vert, int count_links);
//int 					**creat_matrix(int size);
//void 					fill_matrix(int **matrix, t_all *all, int size);
void 					fill_graph(t_graph *graph, t_all *all, int count);
void					print_graph(t_graph *graph);
void					rec_f(t_all *all, t_graph *graph, t_node *node, int dep);
struct					s_node * find_node(t_graph *graph, char *dest, char *begin);
#endif
