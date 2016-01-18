#ifndef FORMAT_H
# define FORMAT_H

#include <macros.h>
#include <parameters.h>

void	init_function(size_t (*functions[MAX_CHAR])(t_printf_data parameters, va_list ap));
size_t	interprete(const char * restrict * format, va_list ap);

size_t	handle_string(t_printf_data parameters, va_list ap);	// s
// S
// p
// d
// D
size_t	handle_int(t_printf_data parameters, va_list ap);		// i
// o
// O
// u
// U
// x
// X
size_t	handle_char(t_printf_data parameters, va_list ap);		// c
// C
size_t	handle_percent(t_printf_data parameters, va_list ap);	// %
size_t	handle_default(t_printf_data parameters, va_list ap);	// Undefined

#endif
