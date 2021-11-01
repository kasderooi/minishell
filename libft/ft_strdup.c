/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:52:11 by niels         #+#    #+#                 */
/*   Updated: 2021/07/03 13:54:09 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char			*des;
	unsigned int	i;

	i = ft_strlen(src);
	des = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!des)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
