#include <ft_printf.h>

size_t	interprete(const char * restrict * format, va_list ap)
{
	t_printf_data		parameters;
	printf_subfunction	function;

	++*format;
	function = init_printf(format, &parameters, ap);
	function(parameters, ap);
	++*format;
	return (0);
}