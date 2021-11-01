/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 10:08:52 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/21 14:49:05 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/expander.h"

static void	retokenize(char ***arg)
{
	int		arg_i;
	t_list	**lst;

	arg_i = 0;
	lst = (t_list **)ft_calloc(sizeof(t_list *), 1);
	check_arr((void **)lst);
	while ((*arg)[arg_i])
	{
		if (ft_strchr((*arg)[arg_i], ' ') && !ft_strchr((*arg)[arg_i], '='))
			tokenizer(lst, (*arg)[arg_i]);
		else
			ft_lstadd_back(lst, ft_lstnew(protect(ft_strdup((*arg)[arg_i]))));
		arg_i++;
	}
	clean_array(*arg);
	*arg = list_to_array(*lst);
	ft_lstclear(lst, free);
	free(lst);
}

static void	expand_subset(t_data *data, char ***arg)
{
	int		arg_i;
	int		i;
	int		mark;

	arg_i = 0;
	i = 0;
	while ((*arg)[arg_i])
	{
		i = 0;
		while ((*arg)[arg_i][i])
		{
			mark = DOWN;
			if (arg_i == 0 && (*arg)[0][i] == '$' && ft_strlen((*arg)[0]) != 1)
			{
				expand_arg(data, &(*arg)[arg_i], &i, &mark);
				retokenize(arg);
				i = -1;
			}
			else if (!(ft_strlen((*arg)[arg_i]) == 1
				&& (*arg)[arg_i][0] == '$'))
				expand_arg(data, &(*arg)[arg_i], &i, &mark);
			i++;
		}
		arg_i++;
	}
}

void	expand_arg(t_data *data, char **str, int *i, int *mark)
{
	int		ex_i;
	char	*buf[3];

	ex_i = 0;
	while (g_expander[ex_i].key != 0)
	{
		if ((*str)[*i] == g_expander[ex_i].key)
		{
			buf[0] = protect(ft_substr(*str, 0, *i));
			buf[1] = g_expander[ex_i].func(data, str, i, mark);
			buf[2] = protect(ft_strjoin_exp(buf[0], buf[1]));
			free(buf[0]);
			free(buf[1]);
			buf[0] = protect(ft_strjoin_exp(buf[2], &(*str)[*i]));
			*i = ft_strlen(buf[2]) - 1;
			free(buf[2]);
			free(*str);
			*str = buf[0];
			break ;
		}
		ex_i++;
	}
}

void	expander(t_data *data, t_tree **tree)
{
	t_tree		*tree_buf;
	t_branch	*branch_buf;

	tree_buf = *tree;
	while (tree_buf)
	{
		branch_buf = *(tree_buf->branch);
		while (branch_buf)
		{
			expand_subset(data, &branch_buf->arg);
			expand_subset(data, &branch_buf->inout);
			branch_buf = branch_buf->next;
		}
		tree_buf = tree_buf->next;
	}
}
