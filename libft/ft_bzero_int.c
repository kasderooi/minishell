/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/05 11:24:16 by kas           #+#    #+#                 */
/*   Updated: 2021/07/05 21:54:25 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero_int(int *ar, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ar[i] = 0;
		i++;
	}
}
