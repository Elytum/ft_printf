#include <ft_printf.h>

void	clear_parameters(t_printf_data *parameters)
{
	bzero(parameters->flags, sizeof(parameters->flags));
	parameters->width = 0;
	parameters->specifier = '\0';
}

static void		init_parameters_buffer(void (*functions[MAX_CHAR])(const char * restrict * format, t_printf_data *parameters, va_list ap))
{
	bzero(functions, sizeof(*functions) * MAX_CHAR);
	functions[(int)*LEFT_JUSTIFY] = &set_justify;
	functions[(int)*FORCE_SIGN] = &set_sign;
	functions[(int)*BLANK_SPACE] = &set_blank;
	functions[(int)*SPECIFICATIONS] = &set_specification;
	functions[(int)*PAD_ZERO] = &set_pad;
	functions['1'] = &set_width_number;
	functions['2'] = &set_width_number;
	functions['3'] = &set_width_number;
	functions['4'] = &set_width_number;
	functions['5'] = &set_width_number;
	functions['6'] = &set_width_number;
	functions['7'] = &set_width_number;
	functions['8'] = &set_width_number;
	functions['9'] = &set_width_number;
	functions['.'] = &set_precision;
	functions['*'] = &set_width_star;
}

void			set_parameters(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	static printf_setters	buffer[MAX_CHAR];
	static char				initialized = 0;
	printf_setters			function;

	if (!initialized)
	{
		initialized = 1;
		init_parameters_buffer(buffer);
	}
	clear_parameters(parameters);
	while ((function = buffer[(int)**format]))
		function(format, parameters, ap);
	parameters->specifier = **format;
}