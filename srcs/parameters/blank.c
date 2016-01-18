#include <parameters.h>

void	set_blank(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[ft_strchr(PARAMETERS, *BLANK_SPACE) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}