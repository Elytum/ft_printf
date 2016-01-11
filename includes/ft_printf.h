#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char * restrict format, ...);




typedef struct	s_printf_data {
	size_t		min_field_width;
}				t_printf_data;

typedef size_t (*printf_subfunction)(const char * restrict * format, t_printf_data parameters, ...);

printf_subfunction	init_printf(const char * restrict * format, t_printf_data *parameters);


void	bufferize(const char *str, size_t len, char flush);






// void	init_function(size_t (*functions[MAX_CHAR])(const char * restrict * format, t_printf_data parameters, ...));
// size_t	handle_special(const char * restrict * format);
// size_t	handle_default(const char * restrict * format, t_printf_data parameters, ...);
// size_t	handle_int(const char * restrict * format, t_printf_data parameters, ...);
// size_t	handle_char(const char * restrict * format, t_printf_data parameters, ...);
// size_t	handle_string(const char * restrict * format, t_printf_data parameters, ...);



void	clear_parameters(t_printf_data *parameters);
void	set_parameters(t_printf_data *parameters);

#include <format.h>

#endif
