#include <unistd.h>
#include <limits.h>

#include <string.h>
#include <stdio.h>

#include <libft.h>

static void		recursion(int i, char **ptr)
{
	if (i >= 10)
	{
		**ptr = i % 10 + '0';
		--*ptr;
		recursion(i / 10, ptr);
	}
	else
		**ptr = i + '0';
}

void			ft_putnbr(int i)
{
	char		buffer[11];
	char		*ptr;
	char		neg;

	if (i == MIN_INT)
		write(1, MIN_INT_STRING, 11);
	else
	{
		if (i < 0)
		{
			neg = 1;
			i = -i;
		}
		else
			neg = 0;
		ptr = buffer + TAB_SIZE(buffer) - 1;
		recursion(-i, &ptr);
		if (neg)
			--*ptr;
			*ptr = '-';
		write(1, ptr - 1, TAB_SIZE(buffer) + buffer - ptr + 1);
	}
}
