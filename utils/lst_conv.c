/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_conv.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 10:15:08 by kas           #+#    #+#                 */
/*   Updated: 2021/07/06 12:52:16 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_in_list(t_list *list, char *arg)
{
	char	*var;
	char	*env;
	t_list	*node;

	node = list;
	var = get_var_name(arg);
	while (node)
	{
		env = get_var_name(node->content);
		if (!ft_strncmp(var, env, ft_strlen(env)) \
			&& !ft_strncmp(var, env, ft_strlen(var)))
		{
			free(node->content);
			node->content = ft_strdup(arg);
			free(var);
			free(env);
			return (1);
		}
		free(env);
		node = node->next;
	}
	free(var);
	return (0);
}

int	lststr(t_data *data, char *str, int nbr)
{
	int		i;
	t_list	*list;

	list = data->token;
	i = 0;
	if (!ft_strncmp("|", list->content, 2)
		|| !ft_strncmp(";", list->content, 2))
		list = list->next;
	while (list && ft_strncmp("|", list->content, 2)
		&& ft_strncmp(";", list->content, 2))
	{
		if (!ft_strncmp(str, list->content, nbr))
			i++;
		list = list->next;
	}
	return (i);
}

char	**list_to_array(t_list *list)
{
	int		len;
	int		i;
	char	**arr;
	t_list	*tmp;

	i = 0;
	tmp = list;
	len = ft_lstsize(tmp);
	arr = (char **)ft_calloc(sizeof(char *), (len + 1));
	check_arr((void **)arr);
	while (tmp && i < len)
	{
		arr[i] = protect(ft_strdup(tmp->content));
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
