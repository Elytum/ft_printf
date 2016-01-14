#include <ft_printf.h>

void	clear_parameters(t_printf_data *parameters)
{
	// bzero(parameters, sizeof(parameters));
	bzero(parameters->flags, sizeof(parameters->flags));
	parameters->width = 0;
}

void	print_parameters(t_printf_data parameters)
{
	static const char	flags[] = PARAMETERS;
	char				*ptr;
	
	ptr = parameters.flags;
	while ((unsigned long)(ptr - parameters.flags) < sizeof(flags) - 1)
	{
		if (*ptr)
			printf("'%c' is activated\n", flags[ptr - parameters.flags]);
		else
			printf("'%c' is not activated\n", flags[ptr - parameters.flags]);
		++ptr;
	}
	printf("Width: %zu\n", parameters.width);
	printf("\n");
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return ((char *)s);
// 		++s;
// 	}
// 	return (NULL);
// }

// size_t	ft_strspn(const char *s1, const char *s2)
// {
// 	const char	*origin = s1;

// 	while (*s1)
// 	{
// 		if (ft_strchr(s2, *s1))
// 			return ((char *)s1 - origin);
// 		++s1;
// 	}
// 	return (0);
// }

void	set_flags(const char * restrict * format, t_printf_data *parameters)
{
	static const char	flags[] = PARAMETERS;
	char				*tmp;

	while (**format)
	{
		if ((tmp = strchr(flags, **format)))
		{
			parameters->flags[tmp - flags] = 1;
			++*format;
		}
		else
			return ;
	}
}

void	set_width(const char * restrict * format, t_printf_data *parameters)
{
	if (**format == '*')
	{
		parameters->width = 5;//extract
		++*format;
	}
	else if (**format >= '0' && **format <= '9')
	{ // To be speeded up by ft_atoip(&str);
		parameters->width = atoi(*format);
		while (**format >= '0' && **format <= '9')
			++*format;
	}
	// else
		// parameters->width = 0;
}

void	set_justify(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->flags[strchr(PARAMETERS, *LEFT_JUSTIFY) - PARAMETERS] = 1;
	++*format;
}

void	set_sign(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->flags[strchr(PARAMETERS, *FORCE_SIGN) - PARAMETERS] = 1;
	++*format;
}

void	set_blank(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->flags[strchr(PARAMETERS, *BLANK_SPACE) - PARAMETERS] = 1;
	++*format;
}

void	set_specification(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->flags[strchr(PARAMETERS, *SPECIFICATIONS) - PARAMETERS] = 1;
	++*format;
}

void	set_pad(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->flags[strchr(PARAMETERS, *PAD_ZERO) - PARAMETERS] = 1;
	++*format;
}

void	set_width_star(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->width = 5; // TO CHANGE
	++*format;
}

void	set_width_number(const char * restrict * format, t_printf_data *parameters, ...)
{
	parameters->width = atoi(*format); // TO OPTIMIZE (Automaticly mote *format)
	while (**format >= '0' && **format <= '9')
		++*format;
}

void	set_precision(const char * restrict * format, t_printf_data *parameters, ...)
{
	++*format;
	if (**format == '*')
	{
		parameters->precision = 3; // TO CHANGE
		++*format;
	}
	else
	{
		parameters->precision = atoi(*format); // TO OPTIMIZE (Automaticly mote *format)
		while (**format >= '0' && **format <= '9')
			++*format;
	}
}

void	init_parameters_buffer(void (*functions[MAX_CHAR])(const char * restrict * format, t_printf_data *parameters, ...))
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
}

void	set_parameters(const char * restrict * format, t_printf_data *parameters, ...)
{
	static printf_setters	buffer[MAX_CHAR];
	static char				initialized = 0;
	printf_setters			function;
	// static const char	skip2[] = "0123456789";
	// const char			*head;

	if (!initialized)
	{
		initialized = 1;
		init_parameters_buffer(buffer);
	}
	clear_parameters(parameters);

	// set_flags(format, parameters);
	// set_width(format, parameters);
	while ((function = buffer[(int)**format]))
		function(format, parameters);
	print_parameters(*parameters);
	// printf("[%s]\n", *format);
	// (*format)++;
	(void)format;

/*
** SET FLAGS AND EXTRACT IDENTIFYING CHARACTER (i, c, s, ...)
*/

}