/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:21:34 by okres             #+#    #+#             */
/*   Updated: 2017/05/15 16:21:39 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*res;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ptr)
		return (NULL);
	res = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	return (res);
}
