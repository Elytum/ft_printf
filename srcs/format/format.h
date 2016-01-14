#ifndef FORMAT_H
# define FORMAT_H

#include <definitions.h>
#include <parameters.h>

void	init_function(size_t (*functions[MAX_CHAR])(const char * restrict * format, t_printf_data parameters, ...));
size_t	handle_special(const char * restrict * format);
size_t	handle_default(const char * restrict * format, t_printf_data parameters, ...);
size_t	handle_int(const char * restrict * format, t_printf_data parameters, ...);
size_t	handle_char(const char * restrict * format, t_printf_data parameters, ...);
size_t	handle_string(const char * restrict * format, t_printf_data parameters, ...);

#endif
