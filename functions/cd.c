/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:10:10 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 11:18:20 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_home_env(t_data *data)
{
	t_list	*node;

	node = data->env;
	while (node)
	{
		if (!ft_strncmp(node->content, "HOME=", 5))
			return (ft_substr(node->content, 5, ft_strlen(node->content) - 5));
		node = node->next;
	}
	return (NULL);
}

void	change_to_home(t_data *data)
{
	char	cwd[PATH_MAX];
	char	*new;

	getcwd(cwd, PATH_MAX);
	new = ft_strjoin("OLDPWD=", cwd);
	add_env(data, new);
	free(new);
	new = get_home_env(data);
	chdir(new);
	free(new);
	getcwd(cwd, PATH_MAX);
	new = ft_strjoin("PWD=", cwd);
	add_env(data, new);
	free(new);
	data->exit_flag = 0;
}

static void	free_path_arg(char *s1, char *s2, char *s3, char *s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}

void	change_to_arg(t_data *data, char *arg)
{
	char	old[PATH_MAX];
	char	new[PATH_MAX];
	char	*paths[4];

	getcwd(old, PATH_MAX);
	if (!chdir(arg))
	{
		getcwd(new, PATH_MAX);
		paths[0] = ft_strdup(old);
		paths[1] = ft_strjoin("OLDPWD=", paths[0]);
		paths[2] = ft_strdup(new);
		paths[3] = ft_strjoin("PWD=", paths[2]);
		add_env(data, paths[1]);
		add_env(data, paths[3]);
		free_path_arg(paths[0], paths[1], paths[2], paths[3]);
		data->exit_flag = 0;
	}
	else
	{
		data->exit_flag = 1;
		ft_putstr_fd("cd: ", 1);
		ft_putstr_fd(arg, 1);
		ft_putendl_fd(": No such file or directory", 1);
	}
}

void	b_cd(t_data *data, t_branch *element)
{
	int	n_args;

	n_args = array_len_char(element->arg);
	if (n_args == 1)
		change_to_home(data);
	else
		change_to_arg(data, element->arg[1]);
}
