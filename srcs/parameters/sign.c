#include <parameters.h>

void	set_sign(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[ft_strchr(PARAMETERS, *FORCE_SIGN) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}