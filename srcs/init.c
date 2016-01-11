#include <ft_printf.h>

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
