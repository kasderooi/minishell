/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 11:59:38 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 19:03:57 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_list(t_list **lst)
{
	t_list	*buf;
	int		check;

	buf = *lst;
	check = 1;
	while (buf)
	{
		if (!ft_strncmp("|", buf->content, 2) && check == 0)
			check = 1;
		else if (!ft_strncmp("|", buf->content, 2) && check == 1)
		{
			ft_lstclear(lst, free);
			return (do_error("syntax error near unexpected token `|'", 1));
		}
		else
			check = 0;
		buf = buf->next;
	}
	return (EXIT_SUCCES);
}

static int	set_index(char *str, int i)
{
	if (i == 0)
		i++;
	if (str[i] == '<' && str[i - 1] == '<')
		i++;
	else if (str[i] == '>' && str[i - 1] == '>')
		i++;
	return (i);
}

/*
*i_dq_sq[0] = index
*i_dq_sq[1] = double quote check
*i_dq_sq[2] = single quote check
*/

int	token_len(char *str)
{
	int	i_dq_sq[3];

	memset(i_dq_sq, 0, sizeof(i_dq_sq));
	while (str[i_dq_sq[0]] == ' ')
		i_dq_sq[0]++;
	while (str[i_dq_sq[0]])
	{
		if (str[i_dq_sq[0]] == '"' && i_dq_sq[1] == 0)
			i_dq_sq[1] = 1;
		else if (str[i_dq_sq[0]] == '"' && i_dq_sq[1] == 1)
			i_dq_sq[1] = 0;
		else if (str[i_dq_sq[0]] == 39 && i_dq_sq[2] == 0)
			i_dq_sq[2] = 1;
		else if (str[i_dq_sq[0]] == 39 && i_dq_sq[2] == 1)
			i_dq_sq[2] = 0;
		else if ((str[i_dq_sq[0]] == ' ' || str[i_dq_sq[0]] == '|'
				|| str[i_dq_sq[0]] == '<' || str[i_dq_sq[0]] == '>')
			&& (i_dq_sq[1] != 1 && i_dq_sq[2] != 1))
		{
			i_dq_sq[0] = set_index(str, i_dq_sq[0]);
			break ;
		}
		i_dq_sq[0]++;
	}
	return (i_dq_sq[0]);
}

int	add_new_thing(t_list **lst)
{
	char	*next_line;
	int		ret;

	write(1, "> ", 2);
	ret = get_next_line(0, &next_line);
	if (ret < 0)
		return (EXIT_FAILURE);
	ret = tokenizer(lst, next_line);
	free(next_line);
	return (ret);
}

int	tokenizer(t_list **lst, char *str)
{
	int		i;
	int		len;
	int		size;

	i = 0;
	size = ft_strlen(str);
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (!str[i])
			break ;
		len = token_len(str + i);
		if (len > 0)
			ft_lstadd_back(lst, ft_lstnew(protect(ft_substr(str, i, len))));
		if (check_list(lst))
			return (EXIT_FAILURE);
		i += len;
		if (i > size)
			break ;
	}
	if (!ft_strncmp("|", ft_lstlast(*lst)->content, 2))
		return (add_new_thing(lst));
	return (EXIT_SUCCES);
}
