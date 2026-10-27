#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
int	    ft_putstr_fd(char *s, int fd);
char    ft_find_specifier(char const *formater, char c);
int     ft_prtf_filter(va_list *args, char specifier);
int     ft_printf(const char *format, ...);

#endif