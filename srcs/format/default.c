#include <ft_printf.h>

size_t	handle_default(t_printf_data parameters, va_list ap)
{
	(void)parameters;
	(void)ap;
	bufferize(&parameters.specifier, 1, 0);
// *format += 2;
	return (0);
}