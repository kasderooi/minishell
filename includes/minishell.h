/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 10:41:24 by nvan-aac      #+#    #+#                 */
/*   Updated: 2021/07/21 18:50:37 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <sys/ioctl.h>

# define UP 1
# define DOWN 0
# define EXIT_SUCCES 0
# define EXIT_FAILURE 1
# define OPEN_Q 2

int					g_last_pid;

typedef struct s_data
{
	t_list			*mem;
	t_list			*env;
	t_list			*env_export;
	t_list			*var;
	t_list			*token;
	char			*line;
	int				run;
	int				std_in;
	int				std_out;
	char			*prompt;
	int				exit_flag;
}					t_data;

typedef struct s_branch
{
	char			**arg;
	int				arg_nbr;
	char			**red;
	char			**inout;
	struct s_branch	*next;
}					t_branch;

typedef struct s_tree
{
	t_branch		**branch;
	int				leaves;
	struct s_tree	*next;
}					t_tree;

/*
---> UTILS
*/

int			do_error(char *str, int err_no);
t_tree		**clean_free(t_tree **tree);
char		*protect(char *str);
void		check_ar(void *array);
void		check_arr(void **array);

int			array_size(char **array);
void		clean_array(char **array);

int			is_in_list(t_list *list, char *arg);
int			lststr(t_data *data, char *str, int nbr);
char		**list_to_array(t_list *list);

/* 
---> LEXER
*/

int			tokenizer(t_list **lst, char *str);
int			token_len(char *str);

/* 
---> PARSING
*/

t_tree		**parser(t_data *data);
int			arg_to_element(char **arg, t_branch *element);

t_branch	*branch_init(t_data *data);
t_branch	*branch_last(t_branch *lst);
void		add_last_branch(t_branch **lst, t_branch *new);
void		clean_branch(t_branch **branch);

t_tree		*tree_init(void);
t_tree		*tree_last(t_tree *lst);
void		add_last_tree(t_tree **lst, t_tree *new);
void		clean_tree(t_tree **tree);

/* 
---> EXPANDER
*/

void		expander(t_data *data, t_tree **tree);
void		expand_arg(t_data *data, char **str, int *i, int *mark);

char		*expand_partq(t_data *data, char **str, int *i, int *mark);
char		*expand_fullq(t_data *data, char **str, int *i, int *mark);

char		*expand_env(t_data *data, char **str, int *i, int *mark);

char		*ft_strjoin_exp(char const *s1, char const *s2);
void		remake_str(char **str, int start, int len);

/* 
---> EXECUTOR
*/

void		executor(t_data *data, t_tree **tree);

void		execute_cmd(t_data *data, t_branch **element, int pid);

void		execute_pipe(t_data *data, t_tree **tree);
void		execute_bin(t_data *data, char **arg, char *path);

int			is_abs_path(t_data *data, t_branch *element);
char		*find_path_env(t_data *data);
char		*get_abs_path(t_data *data, t_branch *element);

int			search_dir(char *dir, char *cmd);
char		*is_builtin(t_data *data, t_branch *element);
void		execute_builtin(t_data *data, t_branch *element);

int			is_variable(t_branch *element);
int			close_set_zero(int i, int *fd);
int			wait_error(t_data *data, int *pid, int processes);
int			fork_init(int **fd, int **pid, t_tree **tree);

/* 
---> REVAMPED BUILTINS
*/

void		b_echo(t_data *data, t_branch *element);
void		b_pwd(t_data *data, t_branch *element);
void		b_cd(t_data *data, t_branch *element);
void		b_exit(t_data *data, t_branch *element);

void		pwd(char **arg);

int			ms_in(char *file);
void		ms_inin(char *file);
int			ms_out(char *file);
int			ms_outout(char *file);

/* 
---> ENVIRONMENT BUILTINS
*/

void		b_env(t_data *data, t_branch *element);
void		b_export(t_data *data, t_branch *element);
void		b_unset(t_data *data, t_branch *pars);

int			print_export_env(t_list *env_export);

char		*get_var_name(char *arg);
char		*get_var(t_list **list, char *str);
void		add_env_export(t_data *data, char *arg);
void		add_env(t_data *data, char *arg);
void		add_var(t_data *data, char *arg);

/*
---> Signals
*/

void		sig_int(int code);
void		sig_quit(int code);

#endif
