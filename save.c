#include <ft_printf.h>

void	clear_parameters(t_printf_data *parameters)
{
parameters->field_width = 0;
parameters->precision = 0;
parameters->have_width = 0;
parameters->have_preci = 0;
}

char	*ft_ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (NULL);
}

size_t	ft_strspn(const char *s1, const char *s2)
{
	const char	*origin = s1;

	while (*s1)
	{
		if (ft_ft_strchr(s2, *s1))
			return ((char *)s1 - origin);
		++s1;
	}
	return (0);
}

void	set_parameters(t_printf_data *parameters, const char * restrict * format)
{
	static const char	skip1[] = "#'-+ 0";
	static const char	skip2[] = "0123456789";
	char				*head;

	clear_parameters(parameters);
	printf("[%s] and [%s]: %zu\n", *format, skip1, ft_strspn(*format, skip1));
	// head = (char *)*format + ft_strspn(*format, skip1);
	// if (*head == '*')
	// {
	// 	//if (getint(&parameters->have_width))
	// 	//	return (NULL)
	// 		parameters->field_width = 3;
	// 	parameters->have_width = 1;
	// 	++head;
	// }
	// else
	// {
	// 	parameters->have_width = 0;
	// 	head += ft_strspn(head, skip2);
	// }
	// if (*head == '.')
	// {
	// 	++head;
	// 	if (*head == '*')
	// 	{
	// 		//if (getint(&parameters->have_width))
	// 		//	return (NULL);
	// 			parameters->precision = 5;
	// 		parameters->have_width = 1;
	// 		parameters->have_preci = 1;
	// 	}
	// 	else
	// 	{
	// 		parameters->have_preci = 0;
	// 		head += ft_strspn(head, skip2);
	// 	}
	// }
	// else
	// 	parameters->have_preci = 0;

	// while ()

	// printf("[%s]\n", *format);
	// (*format)++;
	(void)format;

/*
** SET FLAGS AND EXTRACT IDENTIFYING CHARACTER (i, c, s, ...)
*/

}