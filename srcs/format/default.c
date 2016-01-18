#include <ft_printf.h>

size_t	handle_default(t_printf_data parameters, va_list ap)
{
	bufferize((const char *)&parameters.specifier, 1, 0);
	return (0);
	(void)ap;
}