NAME= libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
AR= ar
ARFLAGS= rcs
SRCS= ft_printf.c \
	$(wildcard converter/*.c) \
	$(wildcard char/*.c) \
	$(wildcard int/*.c) \
	$(wildcard pointer/*.c) \
OBJS= $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re