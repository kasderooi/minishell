/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_abs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 14:49:08 by kas           #+#    #+#                 */
/*   Updated: 2021/07/06 10:51:08 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_join_abs_path(char *first, char *sec)
{
	free(first);
	free(sec);
}

int	is_abs_path(t_data *data, t_branch *element)
{
	(void)data;
	if (ft_strchr(element->arg[0], '/'))
		return (1);
	return (0);
}

char	*find_path_env(t_data *data)
{
	t_list	*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (!ft_strncmp("PATH=", tmp->content, 5))
			return (protect(ft_strdup(tmp->content + 5)));
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_abs_path(t_data *data, t_branch *element)
{
	char	**dir;
	char	*ret[3];
	int		i;

	ret[2] = find_path_env(data);
	if (ret[2] == NULL)
		return (NULL);
	dir = ft_split(ret[2], ':');
	check_arr((void *)dir);
	i = 0;
	while (dir[i])
	{
		if (search_dir(dir[i], element->arg[0]))
		{
			ret[0] = protect(ft_strjoin("/", element->arg[0]));
			ret[1] = protect(ft_strjoin(dir[i], ret[0]));
			free_join_abs_path(ret[0], ret[2]);
			free_split(dir);
			return (ret[1]);
		}
		i++;
	}
	free_split(dir);
	free(ret[2]);
	return (NULL);
}
