NAME		= libft.a

CFLAGS		= -Wall -Werror -Wextra -c

FILES 		=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_strlen.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlcpy.c \
					ft_strdup.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strnstr.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_isascii.c \
					ft_striteri.c \
					ft_strmapi.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_putchar_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_calloc.c \
					ft_substr.c	\
					ft_atol.c \

FILES_B		= 		ft_lstnew.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstiter.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstadd_front.c \
					ft_lstadd_back.c \
					ft_lstmap.c \


OBJ		=	$(FILES:.c=.o)
OBJ_B	=	$(FILES_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $(OBJ) $(OBJ_B)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

$(OBJ_B): $(FILES_B)
	gcc $(CFLAGS) $(FILES_B)

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus clean fclean all re
