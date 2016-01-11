#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#include <ft_printf.h>

int		ft_printf(const char * restrict format, ...)
{
	const char	*ptr;

	while (*format)
	{
		if (*format == '%')
			handle_special(&format);
		else
		{
			ptr = format;
			while (*format && *format != '%')
				++format;
			bufferize(ptr, format - ptr, 0);
		}
	}
	bufferize(NULL, 0, 1);
	return (0);
}