/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 23:31:36 by niels         #+#    #+#                 */
/*   Updated: 2020/11/03 12:41:32 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;
	size_t	total;

	total = size * count;
	new = malloc(total);
	if (!new)
		return (NULL);
	i = 0;
	while (total - i > 0)
	{
		new[i] = 0;
		i++;
	}
	return ((void *)new);
}
