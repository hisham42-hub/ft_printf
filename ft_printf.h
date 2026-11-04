#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include <stdio.h>

int     ft_print_char(char c, int fd);
int     ft_bs_converter(unsigned long long, char *base, int base_len, int fd);
int	    ft_putchar_fd(char c, int fd);
int	    ft_putstr_fd(char *s, int fd);
int	    ft_putint_fd(long long n, int fd);
int     ft_putuint_fd(unsigned long n, int fd);
int     ft_puthex_fd (unsigned long n,char hx,int fd);
int     ft_putptr_fd(void *ptr, int fd);
int     ft_printf(const char *format, ...);

#endif