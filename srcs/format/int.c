#include <ft_printf.h>

size_t	handle_int(const char * restrict * format, t_printf_data parameters, ...)
{
	(void)parameters;
	bufferize("int", 3, 0);
	++*format;
	return (0);
}
