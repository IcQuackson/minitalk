NAME = minitalk

FLAGS = -g -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	server client

server: server.c aux.c
	@cd ft_printf && make
	@cc $(FLAGS) $^ -o $@ ft_printf/libftprintf.a

client: client.c aux.c
	@cd ft_printf && make
	@cc $(FLAGS) $^ -o $@ ft_printf/libftprintf.a

clean:
		@rm -rf *.o
		@cd ft_printf && make clean

fclean:	clean
		@rm -rf server client
		@cd ft_printf && make fclean

re:		fclean all

main: 	all
		./server