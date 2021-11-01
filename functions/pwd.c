/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/17 13:29:58 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 10:47:44 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	b_pwd(t_data *data, t_branch *element)
{
	char	cwd[PATH_MAX];

	(void)data;
	(void)element;
	if (getcwd(cwd, PATH_MAX))
		ft_putendl_fd(cwd, 1);
	data->exit_flag = 0;
}
