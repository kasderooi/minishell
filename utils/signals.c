/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 11:55:12 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 19:13:26 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_int(int code)
{
	(void)code;
	if (!g_last_pid || g_last_pid == -1)
	{
		ft_putendl_fd("", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_last_pid == -2)
	{
		g_last_pid = -3;
		ft_putendl_fd("", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		ioctl(0, TIOCFLUSH, 2);
		close(0);
	}
	else if (g_last_pid > 0)
		ft_putendl_fd("", 2);
}

void	sig_quit(int code)
{
	if (g_last_pid > 0)
		printf("Quit: %d\n", code);
	else if (!g_last_pid)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_last_pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
