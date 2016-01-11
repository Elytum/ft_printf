#include <ft_printf.h>

size_t	handle_special(const char * restrict * format)
{
	t_printf_data		parameters;
	printf_subfunction	function;

	++*format;
	function = init_printf(format, &parameters);
	function(format, parameters);
	return (0);
}