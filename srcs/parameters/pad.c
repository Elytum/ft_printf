#include <parameters.h>

void	set_pad(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *PAD_ZERO) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}