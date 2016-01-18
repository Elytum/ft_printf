#include <ft_printf.h>
#include <libft.h>

size_t	handle_percent(t_printf_data parameters, va_list ap)
{
	if (parameters.width > 1)
	{
		if (parameters.flags[ft_strchr(PARAMETERS, *LEFT_JUSTIFY) - PARAMETERS])
		{
			bufferize("%", 1, 0);
			bufferize_char(' ', parameters.width - 1, 0);
		}
		else
		{
			if (parameters.flags[ft_strchr(PARAMETERS, *PAD_ZERO) - PARAMETERS])
				bufferize_char('0', parameters.width - 1, 0);
			else
				bufferize_char(' ', parameters.width - 1, 0);
			bufferize("%", 1, 0);
		}
	}
	else
		bufferize("%", 1, 0);
	return (0);
	(void)ap;
}
