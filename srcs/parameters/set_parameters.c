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
	printf("Precision: %zu\n", parameters.precision);
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

void	set_flags(const char * restrict * format, t_printf_data *parameters, va_list ap)
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
	(void)ap;
}

// void	set_width(const char * restrict * format, t_printf_data *parameters, va_list ap)
// {
// 	dprintf(1, "Setting: [%s]\n", *format);
// 	if (**format == '*')
// 	{
// 		dprintf(1, "Extracting int\n");
// 		parameters->width = va_arg(ap, int);
// 		++*format;
// 	}
// 	else if (**format >= '0' && **format <= '9')
// 	{ // To be speeded up by ft_atoip(&str);
// 		parameters->width = atoi(*format);
// 		while (**format >= '0' && **format <= '9')
// 			++*format;
// 	}
// 	// else
// 		// parameters->width = 0;
// 	(void)ap;
// }

void	set_precision(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	++*format;
	if (**format == '*')
	{
		parameters->precision = va_arg(ap, int);
		++*format;
	}
	else
	{
		parameters->precision = atoi(*format); // TO OPTIMIZE (Automaticly mote *format)
		while (**format >= '0' && **format <= '9')
			++*format;
	}
}

void	set_justify(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *LEFT_JUSTIFY) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}

void	set_sign(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *FORCE_SIGN) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}

void	set_blank(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *BLANK_SPACE) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}

void	set_specification(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *SPECIFICATIONS) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}

void	set_pad(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->flags[strchr(PARAMETERS, *PAD_ZERO) - PARAMETERS] = 1;
	++*format;
	(void)ap;
}

void	set_width_star(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->width = va_arg(ap, int);
	++*format;
	(void)ap;
}

void	set_width_number(const char * restrict * format, t_printf_data *parameters, va_list ap)
{
	parameters->width = atoi(*format); // TO OPTIMIZE (Automaticly mote *format)
	while (**format >= '0' && **format <= '9')
		++*format;
	(void)ap;
}

void	init_parameters_buffer(void (*functions[MAX_CHAR])(t_printf_data *parameters, va_list ap))
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

void	set_parameters(const char * restrict * format, t_printf_data *parameters, va_list ap)
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
	// dprintf(1, "Format: [%s]\n", *format);
	while ((function = buffer[(int)**format]))
		function(parameters, ap);
	++*format;
	// print_parameters(*parameters);
	// printf("[%s]\n", *format);
	// (*format)++;
	(void)format;

/*
** SET FLAGS AND EXTRACT IDENTIFYING CHARACTER (i, c, s, va_list ap)
*/

}