/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 11:49:51 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 10:09:29 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

typedef struct s_builtin
{
	char	*key;
	void	(*func)(t_data *, t_branch *);
}			t_builtin;

t_builtin	g_builtin[] = {
		{"echo", &b_echo},
		{"pwd", &b_pwd},
		{"unset", &b_unset},
		{"export", &b_export},
		{"env", &b_env},
		{"cd", &b_cd},
		{"exit", &b_exit},
		{0, NULL}
};

#endif
