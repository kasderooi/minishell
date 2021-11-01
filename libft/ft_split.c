/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:51:01 by niels         #+#    #+#                 */
/*   Updated: 2021/04/07 11:30:31 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	if (i == ft_strlen(s))
		return (0);
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && i != ft_strlen(s) - 1)
			count++;
		i++;
	}
	return (count + 1);
}

static char	*make_substring(const char *s, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	len;

	i = 0;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i] != c && s[i])
		i++;
	len = i;
	return (ft_substr(s, start, len - start));
}

static	char	**freee_split(char **split, unsigned int index)
{
	int	i;

	i = (int)index;
	while (i >= 0)
	{
		free((void *)split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	j;
	char			**split;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	j = 0;
	while (j < count)
	{
		split[j] = make_substring(s, c);
		if (!split[j])
			return (freee_split(split, j));
		while (*s == c)
			s++;
		s = ft_memchr(s, (int)c, ft_strlen(s));
		j++;
	}
	split[j] = NULL;
	return (split);
}
