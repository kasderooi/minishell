/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_lst.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 10:51:27 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/06 13:30:16 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_branch	*branch_init(t_data *data)
{
	t_branch	*elem;

	elem = (t_branch *)ft_calloc(1, sizeof(t_branch));
	check_ar((void *)elem);
	elem->arg = NULL;
	elem->arg_nbr = 0;
	elem->arg_nbr -= lststr(data, "<", 1);
	elem->arg_nbr -= lststr(data, ">", 1);
	elem->inout = (char **)ft_calloc((elem->arg_nbr * -1) + 1, sizeof(char *));
	check_arr((void **)elem->inout);
	elem->red = (char **)ft_calloc((elem->arg_nbr * -1) + 1, sizeof(char *));
	check_arr((void **)elem->red);
	elem->arg_nbr *= 2;
	elem->next = NULL;
	return (elem);
}

t_branch	*branch_last(t_branch *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (lst->next == NULL)
			return (lst);
	}
	return (lst);
}

void	add_last_branch(t_branch **lst, t_branch *new)
{
	t_branch	*buf;

	buf = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		buf = branch_last(*lst);
		buf->next = new;
	}
}

void	clean_branch(t_branch **branch)
{
	t_branch	*buf;

	clean_array((*branch)->arg);
	clean_array((*branch)->red);
	clean_array((*branch)->inout);
	buf = (*branch)->next;
	free(*branch);
	*branch = buf;
}
