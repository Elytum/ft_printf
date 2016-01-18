#include <ft_printf.h>

void	init_function(size_t (*functions[MAX_CHAR])(t_printf_data parameters, va_list ap))
{
	int		i;

	i = 0;
	while (i < MAX_CHAR)
		functions[i++] = &handle_default;
	functions['i'] = &handle_int;
	functions['c'] = &handle_char;
	functions['s'] = &handle_string;
}