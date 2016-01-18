#include <parameters.h>

void	set_precision(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	++*format;
	if (**format == '*')
	{
		parameters->precision = va_arg(ap, int);
		++*format;
	}
	else
	{
		parameters->precision = atoi(*format); // TO OPTIMIZE (Automaticly mote *format)
		while (**format >= '0' && **format <= '9')
			++*format;
	}
}