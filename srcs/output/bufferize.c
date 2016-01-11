#include <ft_printf.h>
#define BUFF_SIZE 4096
#include <string.h>
#include <unistd.h>

size_t	bufferize_too_long(char *buffer, const char *str, size_t size, size_t len)
{
	size_t			add;

	if (size + len > TAB_SIZE(buffer) * 2)
	{
		write(1, buffer, size);
		write(1, str, len);
		return (0);
	}
	else
	{
		add = TAB_SIZE(buffer) - size;
		memcpy(buffer + size, str, add);
		write(1, buffer, TAB_SIZE(buffer));

		size = len - add;
		memcpy(buffer, str + add, size);
		return (size);
	}
}

void	bufferize(const char *str, size_t len, char flush)
{
	static char		buffer[BUFF_SIZE];
	static size_t	size = 0;

	if (size + len > TAB_SIZE(buffer))
		size = bufferize_too_long(buffer, str, size, len);
	else
	{
		memcpy(buffer + size, str, len);
		size += len;
	}
	if (flush && size)
	{
		write(1, buffer, size);
		size = 0;
	}
}