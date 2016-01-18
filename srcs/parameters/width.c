#include <parameters.h>

void	set_width_star(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->width = va_arg(ap, int);
	++*format;
	(void)ap;
}

void	set_width_number(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->width = atoi(*format); // TO OPTIMIZE (Automaticly mote *format)
	while (**format >= '0' && **format <= '9')
		++*format;
	(void)ap;
}