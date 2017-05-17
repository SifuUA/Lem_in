/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:43:19 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 17:43:21 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include "libft/libft.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define CLEAR           "\033[2J"
# define RETUR        "\033[0;0f"

# define STOP 77777777

typedef struct			s_node
{
	int					mark;
	char				*dest;
	char				*begin;
	struct s_node		*next;
}						t_node;

typedef struct			s_head
{
	struct s_node		*head;
	char				*name;
}						t_head;

typedef struct			s_graph
{
	long int			count_vert;
	struct s_head		*array;
}						t_graph;

typedef struct			s_llist
{
	struct s_head		head;
}						t_llist;

typedef struct			s_all
{
	char				*start;
	struct s_head		start_node;
	char				*end;
	char				**links;
	char				**verticies;
	int					link;
	long int			ants;
	int					flag;
	char				**res;
	int					i;
	char				*dest;
	int					j;
	int					k;
	int					z;
	int					r_rec;
	char				**fin_res;
	int					*storage;
	int					*stoper;
	t_node				*ss;
	t_node				*start_save;
	t_node				*tmp;
}						t_all;

void					fill_all(t_all *all, char **str);
int						len_arr(char **arr);
void					free_arr(char **arr);
void					check(t_all *all);
int						find(char **str, char *c);
int						find_index(t_head *arr, char *str);
void					control_ch(int flag, char *str);
int						count_links(char **str);
int						count_vert(char **str);
t_graph					*creat_graph(long int count_v);
t_all					*creat_struct(long int count_vert, int count_links);
void					fill_graph(t_graph *graph, t_all *all, int count);
void					print_graph(t_graph *graph);
void					rec_f(t_all *all, t_graph *graph, t_node *node,
						int dep);
struct s_node			*find_node(t_graph *graph, char *dest,
						char *begin);
char					*clear_other(char **p, char *str);
int						if_all_mark(t_node *node);
char					*get_to(char *str, char *to);
struct s_node			*find_node(t_graph *graph, char *dest, char *begin);
int						check_res(char *res, char *str);
void					choose_ways(t_all *all, int i, char **sample,
						int **matrix);
char					**check_matrix(int **matrix, int len, char **sample);
char					**clear(char **str, int size);
void					fill_matrix(int **matrix, char **sample, int size,
						t_all *all);
int						if_contain(char **s1, char **s2);
char					*ft_strjoin_mod2(char const *s1, char const *s2);
void					run(t_all *all);
void					free_tmp(char **tmp, char **tmp1, int *i);
void					free_int_arr(int **arr);
void					write_ants(t_all *all, char *str);
void					stoper(t_all *all);
int						**get_ar(t_all *all, int i, int length, char **tmp);
int						len_int_ar(int *ar);
void					print_way(char **res, int i, int j, int ant);
void					choose_ways_pre(t_all *all);
void					put_error(void);
int						c_t(char **f_res, char *str);
#endif
