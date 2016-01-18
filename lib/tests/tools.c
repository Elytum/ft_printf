#include <libft.h>
#include <timer.h>
#include <unistd.h>

void				tell_function_delay(const char *function_name, const char *extra)
{
	const char		intro[] = "The function \"";
	const char		delay[] = "\" took ";
	const char		outro[] = " miliseconds to be executed !";

	write(2, intro, ft_strlen(intro));
	write(2, function_name, ft_strlen(function_name));
	write(2, delay, ft_strlen(delay));
	tell_timer();
	write(2, outro, ft_strlen(outro));
	if (extra)
		write(2, extra, ft_strlen(extra));
	write(2, "\n", 1);
}

void				put_str_array(char **array)
{
	while (*array)
	{
		write(1, *array, ft_strlen(*array));
		write(1, "\n", 1);
		++array;
	}
}