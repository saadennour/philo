NAME = philo

CC = gcc

SRCS = philo.c tools.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -pthread -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all
