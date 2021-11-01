/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 12:39:20 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/06/30 10:48:25 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executor(t_data *data, t_tree **tree)
{
	while (*tree)
	{
		if ((*tree)->leaves > 1)
			execute_pipe(data, tree);
		else
			execute_cmd(data, (*tree)->branch, 1);
		clean_tree(tree);
	}
	free(tree);
}
