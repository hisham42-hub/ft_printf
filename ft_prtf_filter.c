#include "ft_printf.h"
int ft_prtf_filter(va_list *args, char specifier)
{
    if(specifier == 'c')
        return (ft_putchar_fd(va_arg(*args,int), 1));
    if(specifier == 's')
        return (ft_putstr_fd(va_arg(*args,char *), 1));

}