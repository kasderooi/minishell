/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_print_exp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:44:48 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/06 10:37:58 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_export_value(char *str)
{
	ft_putchar_fd('"', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('"', 1);
}

int	print_export_env(t_list *env_export)
{
	int		i;
	char	*str;

	while (env_export)
	{
		i = 0;
		while (((char *)env_export->content)[i] \
			&& ((char *)env_export->content)[i] != '=')
			i++;
		i++;
		ft_putstr_fd("declare -x ", 1);
		str = ft_substr(env_export->content, 0, i);
		ft_putstr_fd(str, 1);
		free(str);
		if (i - 1 != (int)ft_strlen(env_export->content))
		{
			str = ft_substr(env_export->content, i, \
				ft_strlen(env_export->content) - i);
			print_export_value(str);
			free(str);
		}
		ft_putchar_fd('\n', 1);
		env_export = env_export->next;
	}
	return (1);
}
