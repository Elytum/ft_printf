#include <libft.h>

#include <string.h>

char		*ft_itoa(int i)
{
	static char		buffer[MAX_INT_SIZE + 2];
	char			*ptr;

	if (i == MIN_INT)
	{
		memcpy(buffer, MIN_INT_STRING, 11);
		return (buffer);
	}
	ptr = buffer + sizeof(buffer) - 1;
	if (i > 0)
	{
		while (i)
		{
			*ptr-- = i % 10 + '0';
			i /= 10;
		}
		return (ptr + 1);
	}
	while (i)
	{
		*ptr-- = - i % 10 + '0';
		i /= 10;
	}
	*ptr = '-';
	return (ptr);
}
