/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 11:41:37 by niels         #+#    #+#                 */
/*   Updated: 2021/04/07 13:20:18 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char *str)
{
	int		min_count;
	long	number;

	number = 0;
	min_count = 0;
	while (*str == '\t' || *str == ' '
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	if (min_count == 1)
		number = -number;
	return (number);
}
