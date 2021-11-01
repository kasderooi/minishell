/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 10:39:30 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 18:55:12 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	init_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_lstadd_back(&data->env, ft_lstnew(protect(ft_strdup(env[i]))));
		ft_lstadd_back(&data->env_export, ft_lstnew(
				protect(ft_strdup(env[i]))));
		ft_lstadd_back(&data->var, ft_lstnew(protect(ft_strdup(env[i]))));
		i++;
	}
}

int	read_line(t_data *data)
{
	int	i;

	i = 0;
	g_last_pid = -1;
	close(0);
	close(1);
	dup2(data->std_in, 0);
	dup2(data->std_out, 1);
	signal(SIGQUIT, &sig_quit);
	signal(SIGINT, &sig_int);
	data->line = readline(data->prompt);
	if (data->line)
		if (data->line[0])
			add_history(data->line);
	return (0);
}

t_data	*init_minishell(char **env)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	check_ar((void *)data);
	init_env(data, env);
	data->run = 1;
	data->std_in = dup(0);
	data->std_out = dup(1);
	data->prompt = "Seglords > ";
	data->exit_flag = 0;
	return (data);
}

static void	expand_and_execute(t_data *data, t_tree **pars)
{
	expander(data, pars);
	executor(data, pars);
}

int	main(int argc, char **argv, char **env)
{
	t_tree	**pars;
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init_minishell(env);
	while (1)
	{
		read_line(data);
		if (!data->line)
			break ;
		if (!data->line[0] || ft_strisspace(data->line))
		{
			free(data->line);
			continue ;
		}
		if (!tokenizer(&data->token, data->line))
		{
			pars = parser(data);
			if (pars)
				expand_and_execute(data, pars);
		}
		free(data->line);
	}
	return (data->exit_flag);
}
