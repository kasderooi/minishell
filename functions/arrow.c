/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arrow.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 09:21:50 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 13:37:31 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <sys/stat.h>
#include <fcntl.h>

int	ms_in(char *file)
{
	int	check;

	check = open(file, O_RDONLY, 0755);
	if (check == -1)
	{
		printf("Seglords: %s: %s\n", file, strerror(errno));
		return (check);
	}
	return (check);
}

void	ms_inin(char *f)
{
	char	*nl;
	int		ret;
	int		fd[2];

	ret = 1;
	pipe(fd);
	g_last_pid = -2;
	while (ret)
	{
		write(2, "> ", 2);
		ret = get_next_line(0, &nl);
		if (ret > 0 && ft_strncmp(f, nl, ft_strlen(f) + 1) && g_last_pid != -3)
		{
			write(fd[1], nl, ft_strlen(nl));
			write(fd[1], "\n", 1);
		}
		else
			ret = 0;
		if (g_last_pid != -3)
			free(nl);
	}
	close(fd[1]);
	if (g_last_pid != -3)
		dup2(fd[0], 0);
	close(fd[0]);
}

int	ms_out(char *file)
{
	return (open(file, O_CREAT | O_WRONLY | O_TRUNC, 0755));
}

int	ms_outout(char *file)
{
	return (open(file, O_CREAT | O_WRONLY | O_APPEND, 0755));
}
