#include <ft_printf.h>
#include <converters.h>

size_t	handle_n(t_printf_data parameters, va_list ap)
{
	int		*value = va_arg(ap, int *);

	*value = get_total(NONE);
	return (0);
	(void)parameters;
}
