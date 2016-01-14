#ifndef PARAMETERS_H
# define PARAMETERS_H

typedef struct	s_printf_data {
	size_t		min_field_width;
}				t_printf_data;

typedef size_t		(*printf_subfunction)(const char * restrict * format, t_printf_data parameters, ...);

printf_subfunction	init_printf(const char * restrict * format, t_printf_data *parameters);
void				clear_parameters(t_printf_data *parameters);
void				set_parameters(t_printf_data *parameters);

#endif
