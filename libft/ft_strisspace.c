/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strisspace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 15:03:56 by niels         #+#    #+#                 */
/*   Updated: 2021/07/16 10:50:02 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisspace(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
