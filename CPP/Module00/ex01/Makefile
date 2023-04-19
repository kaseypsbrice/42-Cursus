SRCS		=	main.cpp PhoneBook.cpp Contact.cpp

INCL		=	Contact.hpp PhoneBook.hpp

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

RM			=	rm -f

NAME		=	MyAwesomePhoneBook

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< 

OBJ			=	$(SRCS:.cpp=.o)

all			:	$(NAME) 

$(NAME)		:	$(OBJ) Contact.hpp PhoneBook.hpp
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all
