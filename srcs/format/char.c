#include <ft_printf.h>

size_t	handle_char(const char * restrict * format, t_printf_data parameters, va_list ap)
{
	const char	value = va_arg(ap, int);

	(void)parameters;
	bufferize(&value, 1, 0);
	++*format;
	return (0);
}
