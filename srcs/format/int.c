#include <ft_printf.h>
#include <converters.h>

size_t	handle_int(const char * restrict * format, t_printf_data parameters, va_list ap)
{
	const int	value = va_arg(ap, int);
	int			len;
	const char	*str = ft_itoa(value, 10, &len);

	// print_parameters(parameters);
	(void)parameters;
	bufferize(str, len, 0);
	++*format;
	return (0);
}
