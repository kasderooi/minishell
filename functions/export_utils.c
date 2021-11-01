/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:14:38 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 12:59:11 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var_name(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	return (ft_substr(arg, 0, i));
}

char	*get_var(t_list **list, char *str)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->content, str, ft_strlen(str)))
			return (ft_strdup(temp->content));
		temp = temp->next;
	}
	return (strdup(str));
}

void	add_var(t_data *data, char *arg)
{
	is_in_list(data->env_export, arg);
	is_in_list(data->env, arg);
	if (!is_in_list(data->var, arg))
		ft_lstadd_back(&data->var, ft_lstnew(ft_strdup(arg)));
	if (is_in_list(data->env_export, arg) && !is_in_list(data->env, arg)
		&& ft_strchr(arg, '='))
		ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(arg)));
}

void	add_env_export(t_data *data, char *arg)
{
	if (!is_in_list(data->env_export, arg) \
		|| !is_in_list(data->env, arg) \
		|| !is_in_list(data->var, arg))
	{
		ft_lstadd_back(&data->var, ft_lstnew(ft_strdup(arg)));
		ft_lstadd_back(&data->env_export, ft_lstnew(ft_strdup(arg)));
	}
}

void	add_env(t_data *data, char *arg)
{
	if (!is_in_list(data->env_export, arg))
		ft_lstadd_back(&data->env_export, ft_lstnew(ft_strdup(arg)));
	if (!is_in_list(data->env, arg))
		ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(arg)));
	if (!is_in_list(data->var, arg))
		ft_lstadd_back(&data->var, ft_lstnew(ft_strdup(arg)));
}
