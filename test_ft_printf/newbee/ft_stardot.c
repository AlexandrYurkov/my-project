#include "ft_printf.h"
#include "libft.h"

int ft_stardot(const char *str, va_list ap, int i, t_flags **flags)
{
    char *tmp;
    int j;
    int flag;

    j = 0;
    if (str[i] == '*')
    {
        flag = va_arg(ap, int);
        if (flag < 0)
        {
            (*flags)->p_star = 1;
            flag *= (-1);
        }
    }
    else
    {
            while (str[i] >= '0' && str[i] <= '9')
            {
                i++;
                j++;
            }
            tmp = malloc((j + 1) * sizeof(char));
            if (!tmp)
                return (0);
            i -= j;
            j = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                tmp[j] = str[i];
                i++;
                j++;
            }
            tmp[j] = '\0';
            flag = ft_atoi(tmp);
            free(tmp);
    }
    return (flag);
}
