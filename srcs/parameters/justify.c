#include <parameters.h>

void	set_justify(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[ft_strchr(PARAMETERS, *LEFT_JUSTIFY) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}