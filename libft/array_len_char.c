/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_len_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 20:23:01 by niels         #+#    #+#                 */
/*   Updated: 2021/04/07 11:28:42 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	array_len_char(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
