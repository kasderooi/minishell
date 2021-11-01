/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:23:44 by niels         #+#    #+#                 */
/*   Updated: 2021/01/20 15:19:26 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  128
# endif

int					get_next_line(int fd, char **line);
int					newline_isset(char *s);
size_t				ft_strlen_gnl(const char *s);
char				*ft_strjoin_gnl(const char *s1, const char *s2);

#endif
