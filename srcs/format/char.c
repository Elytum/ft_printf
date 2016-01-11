#include <ft_printf.h>

size_t	handle_char(const char * restrict * format, t_printf_data parameters, ...)
{
	(void)parameters;
	bufferize("char", 4, 0);
	++*format;
	return (0);
}
