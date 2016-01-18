#include <ft_printf.h>

void	init_function(size_t (*functions[MAX_CHAR])(t_printf_data parameters, va_list ap))
{
	int		i;

	i = 0;
	while (i < MAX_CHAR)
		functions[i++] = &handle_default;

	functions['s'] = &handle_string;
	// functions['S'] = &handle_int;
	// functions['p'] = &handle_int;
	functions['d'] = &handle_int;
	// functions['D'] = &handle_int;
	functions['i'] = &handle_int;
	// functions['o'] = &handle_int;
	// functions['O'] = &handle_int;
	// functions['u'] = &handle_int;
	// functions['U'] = &handle_int;
	// functions['x'] = &handle_int;
	// functions['X'] = &handle_int;
	functions['c'] = &handle_char;
	// functions['C'] = &handle_int;
	functions['%'] = &handle_percent;
	functions['n'] = &handle_n;
}
