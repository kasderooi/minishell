/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:10:16 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 10:47:17 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	newline_check(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	b_echo(t_data *data, t_branch *element)
{
	int	i;
	int	no_newline;

	(void)data;
	i = 1;
	no_newline = 0;
	while (newline_check(element->arg[i]))
	{
		no_newline = 1;
		i++;
	}
	while (element->arg[i])
	{
		ft_putstr_fd(element->arg[i], 1);
		if (element->arg[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!no_newline)
		ft_putendl_fd("", 1);
	data->exit_flag = 0;
}
