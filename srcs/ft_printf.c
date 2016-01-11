#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 4096
#define TAB_SIZE(tab) (sizeof(tab) / sizeof(tab[0]))

typedef size_t (*printf_subfunction)(const char * restrict * format, const char *flags, ...);

size_t	bufferize_too_long(char *buffer, const char *str, size_t size, size_t len)
{
	size_t			add;

	if (size + len > TAB_SIZE(buffer) * 2)
	{
		write(1, buffer, size);
		write(1, str, len);
		return (0);
	}
	else
	{
		add = TAB_SIZE(buffer) - size;
		memcpy(buffer + size, str, add);
		write(1, buffer, TAB_SIZE(buffer));

		size = len - add;
		memcpy(buffer, str + add, size);
		return (size);
	}
}

void	bufferize(const char *str, size_t len, char flush)
{
	static char		buffer[BUFF_SIZE];
	static size_t	size = 0;

	if (size + len > TAB_SIZE(buffer))
		size = bufferize_too_long(buffer, str, size, len);
	else
	{
		memcpy(buffer + size, str, len);
		size += len;
	}
	if (flush && size)
	{
		write(1, buffer, size);
		size = 0;
	}
}

size_t	handle_int(const char * restrict * format, const char *flags, ...)
{
	(void)flags;
	bufferize("int", 3, 0);
	++*format;
	return (0);
}

size_t	handle_char(const char * restrict * format, const char *flags, ...)
{
	(void)flags;
	bufferize("char", 4, 0);
	++*format;
	return (0);
}

size_t	handle_string(const char * restrict * format, const char *flags, ...)
{
	(void)flags;
	bufferize("string", 6, 0);
	++*format;
	return (0);
}

void	init_function(size_t (*functions[256])(const char * restrict * format, const char *flags, ...))
{
	functions['i'] = &handle_int;
	functions['c'] = &handle_char;
	functions['s'] = &handle_string;
}

printf_subfunction	init_printf(const char * restrict * format, char *flags)
{
	static printf_subfunction	functions[256];
	static size_t				initialized = 0;

	if (initialized == 0)
	{
		initialized = 1;
		init_function(functions);
	}
	(void)format;
	bzero(flags, TAB_SIZE(flags));
/*
** SET FLAGS AND EXTRACT IDENTIFYING CHARACTER (i, c, s, ...)
*/

	return (functions[(int)**format]);
}

size_t	handle_format(const char * restrict * format)
{
	static char			flags[256];
	printf_subfunction	function;

	++*format;
	if ((function = init_printf(format, flags)))
		function(format, flags);
	return (0);
}

int		ft_printf(const char * restrict format, ...)
{
	const char	*ptr;

	while (*format)
	{
		if (*format == '%')
			handle_format(&format);
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