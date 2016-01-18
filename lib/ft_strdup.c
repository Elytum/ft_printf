#include <libft.h>

#include <string.h>

char		*ft_strdup(const char *str)
{
	const size_t	len = ft_strlen(str);
	const char		*dup = (char *)malloc(sizeof(char) * len);

	if (!dup)
		return(NULL);
	return (memcpy((void *)dup, str, len));
}
