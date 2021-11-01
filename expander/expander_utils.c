/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 12:43:08 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/07/02 21:22:43 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strjoin_exp(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*join;

	len = 0;
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	len = ft_strlen((char *)s1);
	len = len + ft_strlen((char *)s2);
	join = (char *)ft_calloc(sizeof(char), (len + 1));
	check_ar((void *)join);
	ft_strlcpy(join, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(join, (char *)s2, len + 1);
	return (join);
}

void	remake_str(char **str, int sta, int len)
{
	char	*buf[3];

	buf[0] = protect(ft_substr(*str, 0, sta));
	buf[1] = protect(ft_substr(*str, sta + len, ft_strlen(&str[0][sta + len])));
	buf[2] = protect(ft_strjoin_exp(buf[0], buf[1]));
	free(buf[0]);
	free(buf[1]);
	free(*str);
	*str = protect(ft_strdup(buf[2]));
	free(buf[2]);
}
