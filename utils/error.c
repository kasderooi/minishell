/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 12:54:57 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/06 10:18:06 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	do_error(char *str, int err_no)
{
	printf("%s: %s\n", str, strerror(err_no));
	return (EXIT_FAILURE);
}

t_tree	**clean_free(t_tree **tree)
{
	while (*(*tree)->branch)
		clean_branch((*tree)->branch);
	clean_tree(tree);
	free(tree);
	return (NULL);
}

char	*protect(char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	return (str);
}

void	check_ar(void *array)
{
	if (!array)
		exit(EXIT_FAILURE);
}

void	check_arr(void **array)
{
	if (!array)
		exit(EXIT_FAILURE);
}
