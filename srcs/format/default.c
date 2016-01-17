#include <ft_printf.h>

size_t	handle_default(const char * restrict * format, t_printf_data parameters, va_list ap)
{
	(void)parameters;
	(void)ap;
	bufferize(*format, 1, 0);
*format += 2;
	return (0);
}