/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 11:24:54 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/06/30 11:17:25 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *c)
{
	if (c)
	{
		ft_putstr_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}
