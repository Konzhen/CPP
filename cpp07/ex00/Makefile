NAME = ex00

SRCS =	main.cpp

OBJS = $(SRCS:%.cpp=%.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re