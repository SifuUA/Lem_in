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
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*s;

    if (!s1)
        return ((char *)s2);
    if (!s2)
        return ((char *)s1);
    s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
    if (s == NULL)
        return (NULL);
    ft_strcat(s, s1);
    ft_strcat(s, s2);
    return (s);
}
*/
/*char	*ft_strjoin(char const *s1, char const *s2)
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
*/