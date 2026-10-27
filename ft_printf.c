#include "ft_printf.h";
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args,format);
    char specifier;
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
            specifier = ft_find_specifier(format);
            count += ft_prtf_filter(&args,specifier);
            format += 2;
        }
    }
    va_end(args);
    return(count);
}
