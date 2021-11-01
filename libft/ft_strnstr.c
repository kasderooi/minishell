/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:53:51 by niels         #+#    #+#                 */
/*   Updated: 2021/04/07 13:20:51 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *hay, const char *n, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*n)
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == n[j] && hay[i + j])
		{
			j++;
			if (!n[j] && i + j <= len)
				return (&((char *)hay)[i]);
		}
		i++;
	}
	return (NULL);
}
