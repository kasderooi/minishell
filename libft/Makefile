NAME	:=	libft.a
SRCS	=	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			ft_memccpy.c ft_strlcpy.c ft_strlen.c ft_strdup.c ft_strlcat.c\
			ft_strndup.c \
			ft_strncmp.c ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c\
			ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isspace.c\
			ft_strisspace.c ft_isprint.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
			ft_putendl_fd.c ft_bzero.c ft_bzero_int.c\
			ft_calloc.c ft_atoi.c ft_strchr.c\
			ft_toupper.c ft_tolower.c ft_split.c ft_itoa.c\
			ft_strnstr.c ft_atof.c ft_putendl.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_isset_bonus.c\
			ft_memalloc_bonus.c ft_memdel_bonus.c ft_strnew_bonus.c\
			get_next_line.c get_next_line_utils.c ft_atol.c\
			array_len_char.c free_split.c
OBJS	=	$(SRCS:.c=.o)
HEADER	=	libft.h

CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OPTIONS = 	ar rcs
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(OPTIONS) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@printf "Building libft objects... %-33.33s\r" $@
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
			@$(RM) $(OBJS)

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re  %.o
