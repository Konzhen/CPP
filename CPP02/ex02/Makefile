NAME = now_we_can_talk

CC = c++

FLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp	\
		Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re bonus
