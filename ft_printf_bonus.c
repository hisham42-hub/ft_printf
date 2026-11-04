#include "ft_printf_bonus.h"

static int handleflags_bonus(char const **format, t_format *fmt )
{
    while(**format)
    {
        if(ft_isconversion_bonus(**format))
            return(**format);
        if(**format == '-')
            fmt->minus = 1;
        else if(**format == '+')
            fmt->plus = 1;
        else if(**format == '0' && fmt->width == 0 && !fmt->dot)
            fmt->zero = 1;
        else if(**format == ' ')
            fmt->space = 1;
        else if(**format == '.')
            fmt->dot = 1;
        else if(**format == '#')
            fmt->hash = 1;
        else if (ft_isdigit(**format) && fmt->dot)
                fmt->precision = (fmt->precision * 10) + (**format - '0');
        else if (ft_isdigit(**format))
                fmt->width = (fmt->width * 10) + (**format - '0');
        (*format)++;
    }
    return (**format);
}

static int print_control_bonus(char const **format, va_list *args, int fd)
{
    t_format fmt;
    char    spec;

    ft_bzero(&fmt,sizeof(t_format));
    spec = handleflags(format, &fmt);
    (*format)++;
    if(spec == 'c')
        return (ft_putchar_fd(va_arg(*args, int), &fmt, fd));
    else if(spec == 's')
        return (ft_putstr_fd(va_arg(*args, char *), &fmt, fd));
    else if(spec == 'd' || spec == 'i')
        return (ft_putint_fd(va_arg(*args, int), &fmt, fd));
    else if(spec == 'u')
        return (ft_putuint_fd(va_arg(*args, unsigned int), &fmt, fd));
    else if(spec == 'x' || spec == 'X')
        return (ft_puthex_fd(va_arg(*args, unsigned int), &fmt, spec, fd));
    else if(spec == 'p')
        return (ft_putptr_fd(va_arg(*args, void *), &fmt, fd));
    else if(spec == '%')
        return (ft_putchar_fd('%', &fmt, fd));
    return(0);
}

int ft_printf_bonus(const char *format, ...)
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
            count +=ft_print_char_bonus(*format,fd);
            format++;
        }
        else
        {
            format++;
            count += print_control_bonus(&format, &args, fd);
        }
    }
    va_end(args);
    return(count);
}
