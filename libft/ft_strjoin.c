/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:52:37 by niels         #+#    #+#                 */
/*   Updated: 2021/06/16 10:33:34 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	len = ft_strlen((char *)s1);
	len = len + ft_strlen((char *)s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(join, (char *)s2, len + 1);
	return (join);
}
