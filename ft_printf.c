#include "ft_printf.h"

static int print_control(char const spec, va_list *args, int fd)
{
    if(spec == 'c')
        return (ft_putchar_fd(va_arg(*args, int), fd));
    else if(spec == 's')
        return (ft_putstr_fd(va_arg(*args, char *), fd));
    else if(spec == 'd' || spec == 'i')
        return (ft_putint_fd(va_arg(*args, int), fd));
    else if(spec == 'u')
        return (ft_putuint_fd(va_arg(*args, unsigned int), fd));
    else if(spec == 'x' || spec == 'X')
        return (ft_puthex_fd(va_arg(*args, unsigned int), spec, fd));
    else if(spec == 'p')
        return (ft_putptr_fd(va_arg(*args, void *), fd));
    else if(spec == '%')
        return (ft_putchar_fd('%', fd));
    return(0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args,format);
    unsigned int    count;  
    int fd;

    count = 0;
    fd = 1;
    while(*format)
    {
        if(*format != '%')
        {
            count +=ft_print_char(*format,fd);
            format++;
        }
        else
        {
            format++;
            count += print_control(*format++, &args, fd);
        }
    }
    va_end(args);
    return(count);
}
