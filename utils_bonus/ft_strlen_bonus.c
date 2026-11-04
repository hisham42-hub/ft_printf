#include "ft_printf_bonus.h" 
int ft_strlen_bonus(char *s)
{
    int i;

    i = 0;
    while(*s)
    {
        s++;
        i++;
    }
    return(i);
}