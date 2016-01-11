#include <ft_printf.h>

size_t	handle_default(const char * restrict * format, t_printf_data parameters, ...)
{
	(void)flags;
	bufferize(*format, 1, 0);
*format += 2;
	return (0);
}