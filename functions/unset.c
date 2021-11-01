/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 13:15:58 by niels         #+#    #+#                 */
/*   Updated: 2021/07/21 11:11:49 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_unset(void *f1, void *f2, void *f3)
{
	free(f1);
	free(f2);
	free(f3);
}

void	remove_node(t_list **list, char *arg)
{
	t_list	*node;
	t_list	*n_p[2];
	char	*var;

	node = *list;
	while (node)
	{
		var = get_var_name(node->content);
		if (!ft_strncmp(var, arg, ft_strlen(arg))
			&& !ft_strncmp(var, arg, ft_strlen(var)))
		{
			n_p[0] = node->next;
			n_p[1] = node->prev;
			if (n_p[0])
				n_p[0]->prev = n_p[1];
			if (n_p[1])
				n_p[1]->next = n_p[0];
			free_unset(node->content, node, var);
			return ;
		}
		free(var);
		node = node->next;
	}
}

void	b_unset(t_data *data, t_branch *element)
{
	int	i;

	i = 1;
	while (element->arg[i])
	{
		remove_node(&data->env, element->arg[i]);
		remove_node(&data->env_export, element->arg[i]);
		remove_node(&data->var, element->arg[i]);
		i++;
	}
	data->exit_flag = 0;
}
