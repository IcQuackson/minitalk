
NAME = libftprintf.a

SRC = ft_putchar ft_putnbr_base ft_putstr ft_printf

BONUS =

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
AR	= ar rcs

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME): $(SRC:=.o)
			@$(AR) $(NAME) $(SRC:=.o)

bonus:	$(BONUS:=.o)
			@$(AR) $(NAME) $(BONUS:=.o)

clean:
			@$(RM)	$(SRC:=.o) $(BONUS:=.o)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all bonus clean fclean re norm