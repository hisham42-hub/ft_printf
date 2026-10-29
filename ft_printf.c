#include "ft_printf.h";

static char    ft_find_specifier(char const *formater)
{
    char    *s;

    s = (char *)formater;
	while (*s)
	{
		if (*s == '%')
			return (*s += 1);
		s++;
	}
	return (NULL);
}

static int ft_print_controller(char *format, va_list *args)
{
    char specifier;

    specifier = ft_find_specifier(format);
    if(specifier == 'c')
        return (ft_putchar_fd(va_arg(*args, int), 1));
    else if(specifier == 's')
        return (ft_putstr_fd(va_arg(*args, char *), 1));
    else if(specifier == 'd' || specifier == 'i')
        return (ft_putint_fd(va_arg(*args, long long), 1));
    else if(specifier == 'u')
        return (ft_putuint_fd(va_arg(*args, unsigned int), 1));
    else if(specifier == 'x' || specifier == 'X')
        return (ft_puthex_fd(va_arg(*args, unsigned int), specifier, 1));
    else if(specifier == 'p')
        return (ft_putptr_fd(va_arg(*args, void *), 1));
    else if(specifier == '%')
        return (ft_putchar_fd('%', 1));

}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args,format);
    unsigned int    count;  

    count = 0;
    while(format)
    {
        if(*format != '%')
        {
            count +=ft_putchar_fd(*format,1);
            format++;
        }
        else
        {
            count += ft_print_controller(format, &args);
            format += 2;
        }
    }
    va_end(args);
    return(count);
}
