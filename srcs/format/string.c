#include <ft_printf.h>
#include <libft.h>

size_t	handle_string(t_printf_data parameters, va_list ap)
{
	const char	*value = va_arg(ap, char *);
	size_t		len = ft_strlen(value);

	if (parameters.width > len)
	{
		if (parameters.flags[ft_strchr(PARAMETERS, *LEFT_JUSTIFY) - PARAMETERS])
		{
			bufferize(value, len, 0);
			bufferize_char(' ', parameters.width - len, 0);
		}
		else
		{
			if (parameters.flags[ft_strchr(PARAMETERS, *PAD_ZERO) - PARAMETERS])
				bufferize_char('0', parameters.width - len, 0);
			else
				bufferize_char(' ', parameters.width - len, 0);
			bufferize(value, len, 0);
		}
	}
	else
		bufferize(value, len, 0);
	return (0);
}