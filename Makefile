NAME	=	minishell

SRCS	=	main.c \
			utils/signals.c utils/error.c utils/ar_conv.c utils/lst_conv.c lexer/lexer.c \
			parser/parser.c parser/pars_lst.c parser/pars_tree_lst.c parser/pars_arg.c \
			expander/expander.c expander/expander_utils.c expander/expand_env.c expander/expand_quote.c \
			executor/executor.c executor/executor_abs.c executor/executor_builtin.c executor/executor_exec.c \
			executor/executor_utils.c executor/execute_cmd.c \
			functions/echo.c functions/pwd.c functions/cd.c functions/unset.c functions/export_print_exp.c \
			functions/export.c functions/export_utils.c functions/env.c functions/exit.c functions/arrow.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I /Users/$(USER)/.brew/opt/readline/include -I/usr/local/opt/readline/include
INC	=		minishell.h \
			libft/get_next_line.h \
			libft/libft.h 

LIBS	=	-L libft -lft -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -L/usr/local/opt/readline/lib

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@make -C libft/
	@echo "\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "You can now run ./minishell, enjoy!"

%.o: %.c
	@printf "Building minishell objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@make clean -C libft/
		@rm -f $(OBJS)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all
