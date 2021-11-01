/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:50:42 by niels         #+#    #+#                 */
/*   Updated: 2020/11/03 12:57:00 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *c, int fd)
{
	if (c && fd >= 0)
	{
		ft_putstr_fd(c, fd);
		ft_putchar_fd('\n', fd);
	}
}
