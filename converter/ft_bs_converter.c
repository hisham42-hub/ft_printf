int     ft_bs_converter(unsigned long long n, char *base, int base_len, int fd)
{
    int count;

    count = 0;
    if(n >= (unsigned long long)base_len)
        count += ft_base_converter((n / base_len), base, base_len, fd);
    count += ft_putchar_fd(base[n % base_len], fd);
    return (count);
}