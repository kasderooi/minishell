/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 14:57:43 by kas           #+#    #+#                 */
/*   Updated: 2021/07/21 19:21:31 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	close_set_zero(int i, int *fd)
{
	int	check;

	check = 0;
	if (i > 0)
	{
		check = close(fd[i - 1]);
		if (check < 0)
			return (do_error("Close error", errno));
		check = dup2(fd[i - 2], 0);
		if (check < 0)
			return (do_error("Dup2 error", errno));
		check = close(fd[i - 2]);
		if (check < 0)
			return (do_error("Close error", errno));
	}
	return (EXIT_SUCCES);
}

int	wait_error(t_data *data, int *pid, int processes)
{
	int	i;
	int	w_status;

	i = 0;
	while (i < processes)
	{
		pid[i] = waitpid(pid[i], &w_status, 0);
		if (pid[i] < 0)
			return (do_error("Wait error", errno));
		if (WIFEXITED(w_status))
			data->exit_flag = WEXITSTATUS(w_status);
		else if (WIFSIGNALED(w_status))
			data->exit_flag = WTERMSIG(w_status) + 128;
		i++;
	}
	return (EXIT_SUCCES);
}

int	fork_init(int **fd, int **pid, t_tree **tree)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	*fd = (int *)malloc(sizeof(int) * ((*tree)->leaves * 2) - 2);
	check_ar((void *)*fd);
	*pid = (int *)malloc(sizeof(int) * (*tree)->leaves);
	check_ar((void *)*pid);
	while (i < ((*tree)->leaves * 2) - 2)
	{
		check = pipe(*fd + i);
		if (check < 0)
			return (do_error("Pipe error", errno));
		i += 2;
	}
	return (EXIT_SUCCES);
}

int	is_variable(t_branch *element)
{
	int	size;
	int	i;

	size = array_len_char(element->arg);
	i = 0;
	while (i < size)
	{
		if (!ft_strchr(element->arg[i], '=')
			|| !ft_isalpha(element->arg[i][0])
			|| !ft_strlen(element->arg[0]))
			return (0);
		i++;
	}
	return (1);
}
