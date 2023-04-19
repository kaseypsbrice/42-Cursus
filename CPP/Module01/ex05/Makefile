NAME 	= Harl

CC 		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJDIR	= .objFiles

SRCS	= main.cpp Harl.cpp
OBJS	= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m

all: $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJS)
	@printf "$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re