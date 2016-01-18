#include <converters.h>

char	*ft_itoa_base(int i, int base, int *len)
{
	/* Room for INT_DIGITS digits, - and '\0' */
	static char		buf[INT_DIGITS + 2];
	char			*p;

	p = buf + INT_DIGITS + 1;
	if (i >= 0) {
		*--p = '0' + (i % base);
		i /= base;
		while (i != 0)
		{
			*--p = '0' + (i % base);
			i /= base;
		}
	}
	else {
		*--p = '0' - (i % base);
		i /= base;
		while (i != 0)
		{
			*--p = '0' - (i % base);
			i /= base;
		}
		*--p = '-';
	}
	*len = sizeof(buf) - 1 - (int)(p - buf);
	return p;
}