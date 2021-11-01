/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:54:39 by niels         #+#    #+#                 */
/*   Updated: 2021/04/07 11:29:11 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	int		i;
	char	*new;

	if (!s1)
		return (NULL);
	start = 0;
	while (is_set(s1[start], set) && s1[start])
		start++;
	len = ft_strlen(s1);
	while (is_set(s1[len - 1], set) && len > start)
		len--;
	new = (char *)malloc((sizeof(char) * (len - start + 1)));
	if (!new)
		return (NULL);
	i = 0;
	while (len > start)
	{
		new[i] = s1[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
