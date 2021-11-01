/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 13:22:39 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/06/30 11:48:10 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

typedef struct s_expander
{
	char	key;
	char	*(*func)(t_data *, char **, int *, int *);
}			t_expander;

t_expander	g_expander[] = {
		{'"', &expand_partq},
		{'\'', &expand_fullq},
		{'$', &expand_env},
		{0, NULL}
};

#endif
