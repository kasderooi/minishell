/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_quote.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 09:30:06 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/21 18:58:50 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*unexpected_eof(char *quote, char *str)
{
	free(str);
	write(2, "Seglords: unexpected EOF while looking for matching `", 53);
	write(2, quote, 1);
	write(2, "'\nSeglords: syntax error: unexpected end of file", 49);
	return (protect(ft_strdup("")));
}

static void	free_quote(void *f1, void *f2)
{
	free(f1);
	free(f2);
}

static char	*open_quote(t_data *data, char *src, char *quote)
{
	char	*next_line;
	char	*buf;
	int		ret[3];

	ret[0] = 1;
	ret[1] = 0;
	while (ret[0] > 0 && ft_strncmp(quote, next_line, 2))
	{
		ret[2] = OPEN_Q;
		buf = ft_strjoin(src, "\n");
		free(src);
		write(1, "> ", 2);
		ret[0] = get_next_line(0, &next_line);
		if (ret[0] > 0 && ft_strncmp(quote, next_line, 2) && g_last_pid != -3)
		{
			expand_arg(data, &next_line, &ret[1], &ret[2]);
			src = ft_strjoin(buf, next_line);
			free_quote(buf, next_line);
		}	
	}
	if (g_last_pid != -3)
		free(next_line);
	if (ft_strncmp(quote, next_line, 2) && g_last_pid != -3)
		buf = unexpected_eof(quote, buf);
	return (buf);
}

char	*expand_partq(t_data *data, char **str, int *i, int *mark)
{
	int		len;
	char	*ret;

	(void)data;
	len = 1 + *i;
	if (*mark != OPEN_Q)
		*mark = UP;
	while ((*str)[len] && (*str)[len] != '"')
	{
		if ((*str)[len] == '$')
			expand_arg(data, str, &len, mark);
		len++;
	}
	ret = protect(ft_substr(*str, *i + 1, len - *i - 1));
	if ((*str)[len] != '"' && *mark != OPEN_Q)
	{
		g_last_pid = -2;
		ret = open_quote(data, ret, "\"");
	}
	*mark = DOWN;
	remake_str(str, *i, len - *i + 1);
	return (ret);
}

char	*expand_fullq(t_data *data, char **str, int *i, int *mark)
{
	int		len;
	char	*ret;

	(void)data;
	if (*mark != OPEN_Q)
		*mark = UP;
	len = 1 + *i;
	while ((*str)[len] && (*str)[len] != '\'')
		len++;
	ret = protect(ft_substr(*str, *i + 1, len - *i - 1));
	if ((*str)[len] != '\'' && *mark != OPEN_Q)
	{
		g_last_pid = -2;
		ret = open_quote(data, ret, "'");
	}
	*mark = DOWN;
	remake_str(str, *i, len - *i + 1);
	return (ret);
}
