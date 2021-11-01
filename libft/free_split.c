/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_split.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 20:18:48 by niels         #+#    #+#                 */
/*   Updated: 2021/04/07 13:19:39 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **split)
{
	size_t	len;

	len = array_len_char(split);
	while (len)
	{
		free(split[len - 1]);
		len--;
	}
	free(split);
}
