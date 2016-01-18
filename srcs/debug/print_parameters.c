#include <debug.h>

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