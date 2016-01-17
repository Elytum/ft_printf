#include <ft_printf.h>

size_t	handle_string(const char * restrict * format, t_printf_data parameters, va_list ap)
{
	const char	*value = va_arg(ap, char *);

	(void)parameters;
	bufferize(value, strlen(value), 0);
	++*format;
	return (0);
}