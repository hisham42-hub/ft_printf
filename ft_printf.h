#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	    ft_putchar_fd(char c, int fd);
int	    ft_putstr_fd(char *s, int fd);
int     ft_bs_converter(unsigned long int, char *base, int base_len, int fd);
int	    ft_putint_fd(int n, int fd);
int     ft_putuint_fd(unsigned int n, int fd);
int     ft_putptr_fd(void *ptr, int fd);
int     ft_printf(const char *format, ...);
#endif