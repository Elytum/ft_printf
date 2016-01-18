#ifndef PARAMETERS_H
# define PARAMETERS_H

#include <definitions.h>

typedef struct	s_printf_data {
	char		flags[sizeof(PARAMETERS) - 1];
	size_t		width;
	size_t		precision;
	char		specifier;
}				t_printf_data;

typedef size_t		(*printf_subfunction)(t_printf_data parameters, va_list ap);
typedef void		(*printf_setters)(const char * restrict * format, t_printf_data *parameters, va_list ap);

printf_subfunction	init_printf(const char * restrict * format, t_printf_data *parameters, va_list ap);
void				clear_parameters(t_printf_data *parameters);
void				set_parameters(const char * restrict * format, t_printf_data *parameters, va_list ap);
size_t				interprete(const char * restrict * format, va_list ap);

#endif
