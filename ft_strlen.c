#include <stdlib.h>

static size_t	any_system(const char *str)
{
	char		*ptr;

	ptr = (char *)str;
	while (*ptr)
		++ptr;
	return (ptr - str);
}

static size_t	four_bytes_testing(const unsigned long int *longword_ptr, const char *str)
{
	const char	*cp = (const char *) (longword_ptr - 1);

	if (cp[0] == 0)
		return cp - str;
	if (cp[1] == 0)
		return cp - str + 1;
	if (cp[2] == 0)
		return cp - str + 2;
	if (cp[3] == 0)
		return cp - str + 3;
	if (sizeof (unsigned long int) > 4)
	{
		if (cp[4] == 0)
			return cp - str + 4;
		if (cp[5] == 0)
			return cp - str + 5;
		if (cp[6] == 0)
			return cp - str + 6;
		if (cp[7] == 0)
			return cp - str + 7;
	}
	return (0);
}

static size_t	fast_check(const unsigned long int	*longword_ptr, const char *str)
{
	unsigned long int		longword;
	unsigned long int		himagic;
	unsigned long int		lomagic;

	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof (unsigned long int) > 4)
	{
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
	while (42)
	{
		longword = *longword_ptr++;

		if (((longword - lomagic) & himagic) != 0)
			return (four_bytes_testing(longword_ptr, str));
	}
}

size_t			ft_strlen(const char *str)
{
	const char *char_ptr;

	if (sizeof(const unsigned long int *) > 8)
		return (any_system(str));

	char_ptr = str;
	while (((unsigned long int) char_ptr & (sizeof (unsigned long int) - 1)) != 0)
	{
		if (*char_ptr == '\0')
			return char_ptr - str;
		++char_ptr;
	}
	return (fast_check((unsigned long int *)char_ptr, str));
}
