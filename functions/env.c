/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:10:19 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 10:47:29 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	b_env(t_data *data, t_branch *element)
{
	t_list	*tmp;

	(void)element;
	tmp = data->env;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	data->exit_flag = 0;
}
