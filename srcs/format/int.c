#include <ft_printf.h>
#include <converters.h>

size_t	handle_int(t_printf_data parameters, va_list ap)
{
	const int	value = va_arg(ap, int);
	int			len;
	const char	*str = ft_itoa_base(value, 10, &len);

	bufferize(str, len, 0);
	return (0);
	(void)parameters;
}
