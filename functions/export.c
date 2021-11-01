/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 10:10:26 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/16 10:47:36 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	print_export_error(char *str)
{
	ft_putstr_fd("Seglords: export: '", 1);
	ft_putstr_fd(str, 1);
	ft_putendl_fd("': not a valid identifier", 1);
	return (1);
}

static int	val_arg_export(t_data *data, char *arg)
{
	int		i;
	int		len;
	char	*str;

	if (!ft_isalpha(arg[0]))
		return (print_export_error(arg));
	str = get_var(&data->var, arg);
	i = 0;
	len = ft_strlen(str);
	while (ft_isalnum(str[i]) && i < len)
		i++;
	if (i == len)
		add_env_export(data, str);
	else if (str[i] == '=')
		add_env(data, str);
	else
		print_export_error(arg);
	free(str);
	return (1);
}

void	b_export(t_data *data, t_branch *element)
{
	int	i;
	int	n_arg;

	n_arg = array_len_char(element->arg);
	i = 1;
	if (n_arg == 1 || !element->arg[1][0])
		print_export_env(data->env_export);
	else
	{
		while (element->arg[i])
		{
			if (element->arg[i][0])
				val_arg_export(data, element->arg[i]);
			i++;
		}
	}
	data->exit_flag = 0;
}
