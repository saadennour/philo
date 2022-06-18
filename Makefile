NAME = philo

CC = gcc

SRCS = philo.c tools.c status.c threads.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all
