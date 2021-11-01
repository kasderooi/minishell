/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 09:27:56 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/09/28 08:46:43 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*find_env_value(t_data *data, char *str, int str_len)
{
	char	*ret;
	t_list	*tmp;

	tmp = data->var;
	while (tmp)
	{
		if (!ft_strncmp(str + 1, tmp->content, str_len - 1))
		{
			ret = protect(ft_strdup(tmp->content + str_len));
			if (!ft_strchr(ret, '='))
				return (ret);
			free(ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static char	*expand_status(t_data *data, char **str, int *i, int *mark)
{
	(void)data;
	(void)str;
	(void)mark;
	remake_str(str, *i, 2);
	return (protect(ft_itoa(data->exit_flag)));
}

char	*expand_env(t_data *data, char **str, int *i, int *mark)
{
	int		len;
	char	*ret;
	int		ret_i[2];

	(void)data;
	len = 1;
	ret_i[0] = 0;
	ret_i[1] = 0;
	if ((*str)[*i + len] == '?')
		return (expand_status(data, str, i, mark));
	while ((*str)[len + *i] && (*str)[len + *i] != ' '
		&& (*str)[len + *i] != '\'' && (*str)[len + *i] != '"'
		&& (*str)[len + *i] != ':' && (*str)[len + *i] != '='
		&& (*str)[len + *i] != '|')
		len++;
	if ((*str)[len + *i] == '"' && *mark == UP)
		*mark = DOWN;
	ret = find_env_value(data, *str + *i, len);
	if (ret)
		expand_arg(data, &ret, &ret_i[0], &ret_i[1]);
	if (len == 1 && (*str)[*i] == '$')
		ret = ft_strdup("$");
	remake_str(str, *i, len);
	return (ret);
}
