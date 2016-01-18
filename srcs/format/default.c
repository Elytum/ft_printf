#include <ft_printf.h>

size_t	handle_default(t_printf_data parameters, va_list ap)
{
	(void)ap;
	bufferize((const char *)&parameters.specifier, 1, 0);
	return (0);
}