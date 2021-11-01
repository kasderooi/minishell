/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cmd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:57:22 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 19:12:15 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exec_abs(t_data *data, char **arg, int pid, char *path)
{
	if (pid)
		pid = fork();
	g_last_pid = pid;
	if (!pid)
		execute_bin(data, arg, path);
	wait_error(data, &pid, 1);
}

static void	exec_var(t_data *data, t_branch **element)
{
	int	i;

	i = 0;
	while ((*element)->arg[i])
	{
		add_var(data, (*element)->arg[i]);
		i++;
	}
}

static void	print_not_found(t_data *data, t_branch **element)
{
	if (!(*element)->arg[0])
		return ;
	data->exit_flag = 127;
	write(2, "Seglords: ", 10);
	write(2, (*element)->arg[0], ft_strlen((*element)->arg[0]));
	write(2, ": command not found\n", 20);
}

static int	redirector(t_branch *element)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (element->red[i])
	{
		if (!ft_strncmp("<", element->red[i], 2))
		{
			check = ms_in(element->inout[i]);
			if (check < 0)
				return (check);
			dup2(check, 0);
		}
		if (!ft_strncmp("<<", element->red[i], 3))
			ms_inin(element->inout[i]);
		if (!ft_strncmp(">", element->red[i], 2))
			dup2(ms_out(element->inout[i]), 1);
		if (!ft_strncmp(">>", element->red[i], 3))
			dup2(ms_outout(element->inout[i]), 1);
		i++;
	}
	return (check);
}

void	execute_cmd(t_data *data, t_branch **element, int pid)
{
	char	*path;

	path = NULL;
	data->run = redirector(*element);
	if ((*element)->arg_nbr == 0 || g_last_pid == -3)
	{
		if (pid > 0 || g_last_pid == -3)
			clean_branch(element);
		g_last_pid = -1;
		return ;
	}
	path = get_abs_path(data, *element);
	if (is_builtin(data, *element) != NULL)
		execute_builtin(data, *element);
	else if (is_variable(*element))
		exec_var(data, element);
	else if (is_abs_path(data, *element) || path != NULL)
		exec_abs(data, (*element)->arg, pid, path);
	else
		print_not_found(data, element);
	free(path);
	if (pid > 0 || g_last_pid == -3)
		clean_branch(element);
}
