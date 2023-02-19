NAME = minitalk

FLAGS = -g -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
		cc $(FLAGS) -o server server.c aux.c
		cc $(FLAGS) -o client client.c aux.c

clean:
		rm -rf *.o

fclean:	clean
		rm -rf server client

re:		fclean all

main: 	all
		./server