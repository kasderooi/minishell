/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 14:48:16 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/09/28 08:34:06 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_cmd_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next != NULL
		&& ft_strncmp("|", lst->content, 2))
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

static char	**convert_list_to_array(t_data *data)
{
	int		i;
	char	**arr;
	t_list	*list;
	t_list	*buf;

	list = data->token;
	arr = (char **)ft_calloc(sizeof(char *), ft_cmd_lstsize(list) + 1);
	check_arr((void **)arr);
	i = 0;
	while (list && ft_strncmp("|", list->content, 2))
	{
		arr[i] = protect(ft_strdup((char *)list->content));
		buf = list->next;
		free(list->content);
		free(list);
		list = buf;
		i++;
	}
	data->token = list;
	return (arr);
}

static void	set_branch(t_data *data, t_tree **tree)
{
	t_list	*list;
	t_list	*buf;

	list = data->token;
	if (!ft_strncmp("|", list->content, 2))
	{
		buf = list->next;
		free(list->content);
		free(list);
		list = buf;
		tree_last(*tree)->leaves++;
	}
	data->token = list;
}

t_tree	**parser(t_data *data)
{
	t_tree		**tree;
	t_branch	*element;
	char		**arg;
	int			error;

	tree = (t_tree **)ft_calloc(1, sizeof(t_tree *));
	check_arr((void **) tree);
	add_last_tree(tree, tree_init());
	while (data->token)
	{
		element = branch_init(data);
		set_branch(data, tree);
		add_last_branch(tree_last(*tree)->branch, element);
		arg = convert_list_to_array(data);
		error = arg_to_element(arg, element);
		clean_array(arg);
		if (error)
			return (clean_free(tree));
	}
	return (tree);
}
