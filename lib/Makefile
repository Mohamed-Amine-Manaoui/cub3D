SRCS			=	checks/ft_isalnum.c\
					checks/ft_isalpha.c\
					checks/ft_isascii.c\
					checks/ft_isdigit.c\
					checks/ft_isprint.c\
					checks/ft_tolower.c\
					checks/ft_toupper.c\
					fds/ft_putnbr_fd.c\
					fds/ft_putstr_fd.c\
					fds/ft_putchar_fd.c\
					fds/ft_putendl_fd.c\
					fds/ft_write_fd.c\
					memes/ft_memchr.c\
					memes/ft_memcmp.c\
					memes/ft_memcpy.c\
					memes/ft_memmove.c\
					memes/ft_memset.c\
					str/ft_strmapi.c\
					str/ft_strchr.c\
					str/ft_strncmp.c\
					str/ft_strcmp.c\
					str/ft_strdup.c\
					str/ft_strnstr.c\
					str/ft_striteri.c\
					str/ft_strjoin.c\
					str/ft_fstrjoin.c\
					str/ft_strtrim.c\
					str/ft_strlcat.c\
					str/ft_substr.c\
					str/ft_strlcpy.c\
					str/ft_strlen.c\
					str/ft_strcat.c\
					str/ft_strcpy.c\
					str/ft_strrchr.c\
					ft_atoi.c\
					ft_itoa.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_split.c\
					garbage_collector.c\
					ft_abs.c\
					ft_realloc.c\
					
OBJS			= $(SRCS:.c=.o)

SRCSB			=	lst/ft_lstnew_bonus.c\
					lst/ft_lstadd_front_bonus.c\
					lst/ft_lstsize_bonus.c\
					lst/ft_lstlast_bonus.c\
					lst/ft_lstadd_back_bonus.c\
					lst/ft_lstdelone_bonus.c\
					lst/ft_lstclear_bonus.c\
					lst/ft_lstiter_bonus.c\
					lst/ft_lstmap_bonus.c
OBJSB			= $(SRCSB:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

BLACK				=	\033[0;30m
GREEN				=	\033[0;32m
PURPLE				=	\033[0;35m
RESET				=	\033[0m
RED					=	\033[0;31m
all:				$(NAME)

$(NAME):		$(OBJS) $(OBJSPF) $(OBJSGNL) $(OBJSM)
				@ar rcs $(NAME) $^
				@printf "$(GREEN)✓  libft\n$(RESET)"

bonus:			$(NAME) $(OBJSB)
				@ar rcs $^
				@printf "$(GREEN)✓  libft bonus\n$(RESET)"

clean:
				@$(RM) $(OBJS) $(OBJSB) $(OBJSPF) $(OBJSGNL) $(OBJSM)
				@printf "$(RED)✗  libft\n$(RESET)"
				@printf "$(RED)✗  libft bonus\n$(RESET)"

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
.SILENT: