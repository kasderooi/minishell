/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 09:45:51 by niels         #+#    #+#                 */
/*   Updated: 2021/02/04 14:51:40 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <math.h>

double	ft_atof(char *str)
{
	double	ret;
	int		count;
	int		is_neg;

	is_neg = 1;
	count = 0;
	ret = (double)ft_atoi(str);
	if (ret < 0 || *str == '-')
	{
		str++;
		is_neg = -1;
	}
	while (ft_isdigit(*str))
		str++;
	count++;
	if (*str != '.')
		return (ret);
	str++;
	while (ft_isdigit(*str))
	{
		ret += ((int)(*str - '0') / pow(10, count) * is_neg);
		count++;
		str++;
	}
	return (ret);
}
