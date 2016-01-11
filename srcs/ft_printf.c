#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#include <ft_printf.h>

void	init_function(size_t (*functions[MAX_CHAR])(const char * restrict * format, const char *flags, ...))
{
	int		i;

	i = 0;
	while (i < MAX_CHAR)
		functions[i++] = &handle_default;
	functions['i'] = &handle_int;
	functions['c'] = &handle_char;
	functions['s'] = &handle_string;
}

void	clear_parameters(t_printf_data *parameters)
{
	parameters->min_field_width = 0;
}

void	set_parameters(t_printf_data *parameters)
{
	clear_parameters(parameters);

/*
** SET FLAGS AND EXTRACT IDENTIFYING CHARACTER (i, c, s, ...)
*/

}

printf_subfunction	init_printf(const char * restrict * format, t_printf_data *parameters)
{
	static printf_subfunction	functions[MAX_CHAR];
	static size_t				initialized = 0;

	if (initialized == 0)
	{
		initialized = 1;
		init_function(functions);
	}
	set_parameters(parameters);
	return (functions[(int)**format]);
}

size_t	handle_format(const char * restrict * format)
{
	// static char			flags[MAX_CHAR];
	t_printf_data		parameters;
	printf_subfunction	function;

	++*format;
	function = init_printf(format, &parameters);
	function(format, parameters);
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