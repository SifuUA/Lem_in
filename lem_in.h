#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"

typedef struct		s_node
{
	struct s_node	*next[];
	struct s_node	*prev;
}					t_str;

typedef struct 		s_lst
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}					t_lst;
#endif
