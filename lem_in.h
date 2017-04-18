#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

typedef struct		s_node
{
	int ar[1000];
	struct s_node	*next;
}					t_str;

typedef struct 		s_list
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;

}					t_list;


#endif
