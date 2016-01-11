#include <ft_printf.h>

void	clear_parameters(t_printf_data *parameters)
{
	parameters->min_field_width = 0;
}

void	set_parameters(t_printf_data *parameters)
{
	clear_parameters(parameters);

/*
** SET FLAGS AND EXTRACT IDENTIFYING CHARACTER (i, c, s, ...)
*/

}