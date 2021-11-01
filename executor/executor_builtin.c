/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_builtin.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 14:54:02 by kas           #+#    #+#                 */
/*   Updated: 2021/07/16 10:46:15 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/builtins.h"

int	search_dir(char *dir, char *cmd)
{
	DIR				*folder;
	struct dirent	*item;
	char			*path;

	path = NULL;
	folder = opendir(dir);
	if (!folder)
		return (0);
	item = readdir(folder);
	while (item)
	{
		if (!ft_strncmp(item->d_name, cmd, ft_strlen(cmd) + 1))
		{
			closedir(folder);
			return (1);
		}
		item = readdir(folder);
	}
	closedir(folder);
	return (0);
}

char	*is_builtin(t_data *data, t_branch *element)
{
	int	i;

	(void)data;
	i = 0;
	while (ft_strncmp(g_builtin[i].key, element->arg[0], 10) \
		&& g_builtin[i].key != NULL)
		i++;
	return (g_builtin[i].key);
}

void	execute_builtin(t_data *data, t_branch *element)
{
	int	i;

	i = 0;
	while (g_builtin[i].key != NULL)
	{
		if (!ft_strncmp(g_builtin[i].key, element->arg[0], 10))
			g_builtin[i].func(data, element);
		i++;
	}
}
