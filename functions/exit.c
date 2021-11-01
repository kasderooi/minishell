/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:10:22 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 13:49:58 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '+' && str[i] != '-'
		&& !ft_isdigit(str[i]))
		return (0);
	if (!ft_isdigit(str[i]) && ft_strlen(str) == 1)
		return (0);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_exit_error(char *str)
{
	printf("Seglords: exit: %s: numeric argument required\n", str);
}

void	b_exit(t_data *data, t_branch *element)
{
	int	n_arg;

	n_arg = array_len_char(element->arg);
	if (g_last_pid == -1)
		ft_putendl_fd("exit", 2);
	if (n_arg == 1)
		exit(data->exit_flag);
	else if (n_arg == 2)
	{
		if (str_isdigit(element->arg[1]))
			exit((unsigned char)ft_atoi(element->arg[1]));
		print_exit_error(element->arg[1]);
		exit(255);
	}
	else
	{
		if (!str_isdigit(element->arg[1]))
		{
			print_exit_error(element->arg[1]);
			exit(255);
		}
		else
			printf("Seglords: exit: too many arguments\n");
		data->exit_flag = 1;
	}
}
