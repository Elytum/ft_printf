#ifndef PARAMETERS_H
# define PARAMETERS_H

#include <definitions.h>
#include <stdarg.h>
#include <stdlib.h>

#include <string.h>
#include <libft.h>

typedef struct	s_printf_data {
	char		flags[sizeof(PARAMETERS) - 1];
	size_t		width;
	size_t		precision;
	size_t		specifier;
}				t_printf_data;

typedef size_t		(*printf_subfunction)(t_printf_data parameters, va_list ap);
typedef void		(*printf_setters)(const char * restrict * format, t_printf_data *parameters, va_list ap);

printf_subfunction	init_printf(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				clear_parameters(t_printf_data *parameters);
void				set_parameters(const char * restrict * format, t_printf_data *parameters, va_list ap);

void				set_width(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_precision(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_justify(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_sign(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_blank(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_specification(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_pad(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_width_star(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				set_width_number(const char * restrict * format, t_printf_data *parameters, va_list ap);

#endif
