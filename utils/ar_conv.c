/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ar_conv.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 10:15:01 by kas           #+#    #+#                 */
/*   Updated: 2021/07/06 10:15:02 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	clean_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}
