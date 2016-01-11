#include <ft_printf.h>

size_t	handle_string(const char * restrict * format, t_printf_data parameters, ...)
{
	(void)parameters;
	bufferize("string", 6, 0);
	++*format;
	return (0);
}