#include <ft_printf.h>

size_t	handle_special(const char * restrict * format, va_list ap)
{
	t_printf_data		parameters;
	printf_subfunction	function;

	++*format;
	function = init_printf(format, &parameters, ap);
	function(format, parameters, ap);
	(void)ap;
	return (0);
}