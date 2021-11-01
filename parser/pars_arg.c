/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_arg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 10:56:07 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/20 14:30:38 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	cmp_inout(char *arg)
{
	if (arg[0] == '<')
		return (1);
	if (arg[0] == '>')
		return (1);
	return (0);
}

static int	seperate_inout(char *arg)
{
	if (!ft_strncmp("<", arg, 2))
		return (1);
	if (!ft_strncmp("<<", arg, 3))
		return (1);
	if (!ft_strncmp(">", arg, 2))
		return (1);
	if (!ft_strncmp(">>", arg, 3))
		return (1);
	return (0);
}

static int	set_inout(char **arg, t_branch *element, int *i)
{
	int	len;

	len = 1;
	if (seperate_inout(arg[i[0]]))
	{
		element->red[i[2]] = protect(ft_strdup(arg[i[0]]));
		i[2]++;
		i[0]++;
		if (!arg[i[0]] || cmp_inout(arg[i[0]]))
			return (do_error("File error", 2));
		element->inout[i[3]] = protect(ft_strdup(arg[i[0]]));
		i[3]++;
		return (EXIT_SUCCES);
	}
	if (arg[i[0]][1] == '<' || arg[i[0]][1] == '>')
		len = 2;
	element->red[i[2]] = protect(ft_substr(arg[i[0]], 0, len));
	i[2]++;
	element->inout[i[3]] = protect(
			ft_substr(arg[i[0]], len, ft_strlen(arg[i[0]])));
	i[3]++;
	return (EXIT_SUCCES);
}

/*
i[0] = source arg array index
i[1] = dest arg array index
i[2] = redirection array index
i[3] = in/out file array index
i[4] = error index
*/
int	arg_to_element(char **arg, t_branch *element)
{
	int		i[5];

	ft_bzero_int(i, 5);
	element->arg_nbr += array_size(&arg[i[0]]);
	if (element->arg_nbr < 0)
		element->arg_nbr = 0;
	element->arg = (char **)ft_calloc(sizeof(char *), element->arg_nbr + 2);
	check_arr((void **)element->arg);
	while (arg[i[0]])
	{
		if (cmp_inout(arg[i[0]]))
			i[4] = set_inout(arg, element, i);
		else
		{
			element->arg[i[1]] = protect(ft_strdup(arg[i[0]]));
			i[1]++;
		}
		if (i[4] == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i[0]++;
	}
	return (EXIT_SUCCES);
}
