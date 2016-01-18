#include <ft_printf.h>

size_t	handle_char(t_printf_data parameters, va_list ap)
{
	const char	value = va_arg(ap, int);

	if (parameters.width > 1)
	{
		if (parameters.flags[strchr(PARAMETERS, *LEFT_JUSTIFY) - PARAMETERS])
		{
			bufferize(&value, 1, 0);
			bufferize_char(' ', parameters.width - 1, 0);
		}
		else
		{
			if (parameters.flags[strchr(PARAMETERS, *PAD_ZERO) - PARAMETERS])
				bufferize_char('0', parameters.width - 1, 0);
			else
				bufferize_char(' ', parameters.width - 1, 0);
			bufferize(&value, 1, 0);
		}
	}
	else
		bufferize(&value, 1, 0);
	return (0);
}
