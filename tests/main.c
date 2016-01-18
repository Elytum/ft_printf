#include <libft.h>
#include <tests.h>
#include <timer.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>

void				test_strsplit(void)
{
	char			**array;

	array = ft_strsplit(TEST_STRING, '*');
	put_str_array(array);
	array[1][0] = 'a';
	put_str_array(array);
	free(array);
}

void				test_putnbr(void)
{
	int				i = TEST_NBR;

	start_timer();
	while (i--)
		ft_putnbr(MIN_INT);
	tell_function_delay("putnbr", NULL);
}

void				test_itoa(void)
{
	int				i = TEST_NBR;

	start_timer();
	while (i--)
		write(1, ft_itoa(MIN_INT), 12);
	tell_function_delay("itoa", NULL);
}

void				test_strlen(void)
{
	int				i = TEST_NBR;
	int				total;

	start_timer();
	while (i--)
		total += ft_strlen(LONG_STRING);
	tell_function_delay("ft_strlen", NULL);
	ft_putnbr(total);
	i = TEST_NBR;
	start_timer();
	while (i--)
		total += strlen(LONG_STRING);
	tell_function_delay("strlen", NULL);
	ft_putnbr(total);
}

void				test_strdup(void)
{
	int				i = TEST_NBR;
	char			*str;

	start_timer();
	while (i--)
	{
		str = ft_strdup(LONG_STRING);
		free(str);
	}
	tell_function_delay("strdup", NULL);
}

int					main(void)
{
	test_strsplit();
	// test_putnbr();
	// test_itoa();
	// test_strlen();
	// test_strdup();
	return (0);
}