#include "ft_printf.h"
int     ft_bs_converter(unsigned long long n, char *base, int base_len, int fd)
{
    int count;

    count = 0;
    if (n == 0)
        return (ft_print_char('0', fd));
    if(n >= (unsigned long long)base_len)
        count += ft_bs_converter((n / base_len), base, base_len, fd);
    count += ft_print_char(base[n % base_len], fd);
    return (count);
}