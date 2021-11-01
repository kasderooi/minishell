/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_exec.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 14:55:35 by kas           #+#    #+#                 */
/*   Updated: 2021/07/20 12:56:12 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	do_child(int i, int *fd, t_data *data, t_tree **tree)
{
	int	check;

	check = 0;
	if (i != ((*tree)->leaves * 2) - 2)
	{
		check = close(fd[i]);
		if (check < 0)
			exit(do_error("Close error", errno));
		check = dup2(fd[i + 1], 1);
		if (check < 0)
			exit(do_error("Dup2 error", errno));
		check = close(fd[i + 1]);
		if (check < 0)
			exit(do_error("Close error", errno));
	}
	execute_cmd(data, (*tree)->branch, 0);
	exit(data->exit_flag);
}

void	execute_bin(t_data *data, char **arg, char *path)
{
	char	**param;
	int		i;
	int		arg_n;

	(void)data;
	i = 0;
	if (data->run == -1)
		exit(EXIT_FAILURE);
	arg_n = array_len_char(arg);
	param = (char **)ft_calloc(sizeof(char *), arg_n + 1);
	check_arr((void *)param);
	if (!param)
		exit(EXIT_FAILURE);
	while (i < arg_n)
	{
		param[i] = arg[i];
		i++;
	}
	if (path == NULL)
		path = protect(ft_strdup(param[0]));
	if (!path)
		exit(EXIT_FAILURE);
	i = execve(path, (char *const *)param, list_to_array(data->env));
	printf("%s: %s\n", param[0], strerror(errno));
	exit(127);
}

void	execute_pipe(t_data *data, t_tree **tree)
{
	int	*pid;
	int	i;
	int	*fd;

	i = 0;
	fork_init(&fd, &pid, tree);
	while (i < ((*tree)->leaves * 2))
	{
		pid[i / 2] = fork();
		g_last_pid = pid[i / 2];
		if (pid[i / 2] < 0)
			printf("Fork error: %s\n", strerror(errno));
		close_set_zero(i, fd);
		if (pid[i / 2] == 0)
			do_child(i, fd, data, tree);
		i += 2;
		clean_branch((*tree)->branch);
	}
	wait_error(data, pid, (*tree)->leaves);
	free(fd);
	free(pid);
}
