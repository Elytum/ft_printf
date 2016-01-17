#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char * restrict format, ...);

#include <format.h>
#include <parameters.h>
void	print_parameters(t_printf_data parameters);
#include <output.h>

#include <stdio.h>
#include <string.h>

#endif
