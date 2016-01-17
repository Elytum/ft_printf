#include <ft_printf.h>
#define BUFF_SIZE 4096
#include <string.h>
#include <unistd.h>

static char		buffer[BUFF_SIZE];
static size_t	size = 0;

static void		bufferize_too_long_char(const char c, size_t len)
{
	memset(buffer + size, c, TAB_SIZE(buffer) - size);
	len -= TAB_SIZE(buffer) - size;
	write(1, buffer, TAB_SIZE(buffer));
	if (len > TAB_SIZE(buffer))
	{
		memset(buffer, c, TAB_SIZE(buffer));
		while (len > TAB_SIZE(buffer))
		{
			write(1, buffer, len);
			len -= TAB_SIZE(buffer);
		}
		size = len;
	}
	else
	{
		size = len;
		memset(buffer, c, size);
	}
}

void			bufferize_char(const char c, size_t len, char flush)
{
	if (size + len > TAB_SIZE(buffer))
		bufferize_too_long_char(c, len);
	else
	{
		memset(buffer + size, c, len);
		size += len;
	}
	if (flush && size)
	{
		write(1, buffer, size);
		size = 0;
	}
}

static void		bufferize_too_long(const char *str, size_t len)
{
	size_t			add;

	if (size + len > TAB_SIZE(buffer) * 2)
	{
		write(1, buffer, size);
		write(1, str, len);
	}
	else
	{
		add = TAB_SIZE(buffer) - size;
		memcpy(buffer + size, str, add);
		write(1, buffer, TAB_SIZE(buffer));

		size = len - add;
		memcpy(buffer, str + add, size);
	}
}

void			bufferize(const char *str, size_t len, char flush)
{
	if (size + len > TAB_SIZE(buffer))
		bufferize_too_long(str, len);
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