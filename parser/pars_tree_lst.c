/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_tree_lst.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 10:51:27 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/06 10:22:44 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tree	*tree_init(void)
{
	t_tree	*unit;

	unit = (t_tree *)ft_calloc(1, sizeof(t_tree));
	check_ar((void *) unit);
	unit->branch = (t_branch **)ft_calloc(1, sizeof(t_branch *));
	check_arr((void **)unit->branch);
	unit->leaves = 1;
	unit->next = NULL;
	return (unit);
}

t_tree	*tree_last(t_tree *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (lst->next == NULL)
			return (lst);
	}
	return (lst);
}

void	add_last_tree(t_tree **lst, t_tree *new)
{
	t_tree	*buf;

	buf = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		buf = tree_last(*lst);
		buf->next = new;
	}
}

void	clean_tree(t_tree **tree)
{
	t_tree	*buf;

	free((*tree)->branch);
	buf = (*tree)->next;
	free(*tree);
	*tree = buf;
}
