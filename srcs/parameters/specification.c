#include <parameters.h>

void	set_specification(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *SPECIFICATIONS) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}