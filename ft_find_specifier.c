#include "ft_printf.h";
char    ft_find_specifier(char const *formater)
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