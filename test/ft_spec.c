int ft_spec(char c, char *str)
{
    while(*str)
    {
        if (*str == c)
        return (c);
        str++;
    }
    return (0);
}