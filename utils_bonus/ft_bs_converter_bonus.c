#include "ft_printf_bonus.h"
int     ft_bs_converter_bonus(unsigned long long n, char *base, int base_len, int fd)
{
    int count;

    count = 0;
    if(n >= (unsigned long long)base_len)
        count += ft_bs_converter_bonus((n / base_len), base, base_len, fd);
    count += ft_print_char_bonus(base[n % base_len], fd);
    return (count);
}