#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_format {
    int minus;
    int plus;
    int space;
    int zero;
    int hash;
    int dot;
    int precision;
    int width;
} t_format;
int     ft_hexlen_bonus(long long n);
int     ft_intlen_bonus(long long n);
int     ft_isconversion_bonus(char c);
int     ft_strlen_bonus(char *s);
int     ft_print_char_bonus(char c, int fd);
int     ft_print_pad_bonus (t_format *fmt, int fd);
void	ft_bzero_bonus(void *s, unsigned int n);
int     ft_isdigit_bonus(char c);
int     ft_isflag_bonus(char c);
int     ft_handle_precision_bonus(long long n,t_format *fmt, int fd, int base);
int     ft_check_pad_bonus(t_format *fmt, long long n, int fd, int base);

int     ft_bs_converter_bonus(unsigned long long, char *base, int base_len, int fd);
int	    ft_putchar_fd_bonus(char c, t_format *fmt, int fd);
int	    ft_putstr_fd_bonus(char *s, t_format *fmt, int fd);
int	    ft_putint_fd_bonus(long long n, t_format *fmt, int fd);
int     ft_putuint_fd_bonus(unsigned long n, t_format *fmt, int fd);
int     ft_puthex_fd_bonus (unsigned long n, t_format *fmt,char hx,int fd);
int     ft_putptr_fd_bonus(void *ptr, t_format *fmt, int fd);
int     ft_printf_bonus(const char *format, ...);
#endif