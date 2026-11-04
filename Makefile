NAME= libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror -I.
AR= ar
ARFLAGS= rcs
SRCS= ft_printf.c char/ft_putchar_fd.c char/ft_putstr_fd.c int/ft_putint_fd.c int/ft_putuint_fd.c pointer/ft_puthex_fd.c pointer/ft_putptr_fd.c utils/ft_bs_converter.c utils/ft_print_char.c
SRCS_BONUS = ft_printf_bonus.c utils_bonus/ft_hexlen_bonus.c utils_bonus/ft_intlen_bonus.c utils_bonus/ft_isconversion_bonus.c utils_bonus/ft_strlen_bonus.c utils_bonus/ft_print_char_bonus.c utils_bonus/ft_print_pad_bonus.c utils_bonus/ft_bzero_bonus.c utils_bonus/ft_isdigit_bonus.c utils_bonus/ft_isflag_bonus.c utils_bonus/ft_handle_precision_bonus.c utils_bonus/ft_bs_converter_bonus.c char/ft_putchar_fd_bonus.c char/ft_putstr_fd_bonus.c int/ft_putint_fd_bonus.c int/ft_putuint_fd_bonus.c pointer/ft_puthex_fd_bonus.c pointer/ft_putptr_fd_bonus.c
OBJS= $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)
bonus: $(OBJS_BONUS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
%_bonus.o: %_bonus.c ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re