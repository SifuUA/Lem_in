/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_recurtion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:46:45 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 15:50:41 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		if_all_mark(t_node *node)
{
	while (node)
	{
		if (node->mark != 1)
			return (0);
		node = node->next;
	}
	return (1);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s == NULL)
		return (NULL);
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}

char	*ft_strjoin_mod2(char const *s1, char const *s2)
{
	char	*s;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s == NULL)
		return (NULL);
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}

char	*clear_other(char **p, char *str)
{
	int		i;
	char	*res;
	char	*tmp;

	i = 0;
	res = NULL;
	while (p[i] && ft_strcmp(p[i], str) != 0)
	{
		tmp = ft_strjoin_mod2(res, p[i]);
		ft_strdel(&res);
		res = ft_strjoin_mod(tmp, " ");
		ft_strdel(&tmp);
		i++;
	}
	tmp = ft_strjoin_mod(res, p[i]);
	ft_strdel(&res);
	res = ft_strjoin_mod(tmp, " ");
	ft_strdel(&tmp);
	return (res);
}
