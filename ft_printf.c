#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int i = 0;

	count = 0;
	va_start(args, format);
	if (!format || (format[0] == '%' && format[1] == '\0')) 
        	return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			count += ft_check_format(args, &format[i + 1]);
			i += 2;
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;	

	}
	va_end(args);
	return (count);
}

int main(void)
{
    ft_printf("%s\n", "");
    printf("%s\n", "");
    return 0;
}
