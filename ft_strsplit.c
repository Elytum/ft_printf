/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 06:13:05 by achazal           #+#    #+#             */
/*   Updated: 2015/11/27 06:13:08 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t		number_of_strings(char **s, char c, size_t *len)
{
	size_t			i;
	char const		*ptr = *s;

	*len = 0;
	i = 0;
	while (*ptr == c)
		++ptr;
	*s = (char *)ptr;
	while (*ptr)
	{
		while (*ptr && *ptr != c)
		{
			++*len;
			++ptr;
		}
		++*len;
		++i;
		while (*ptr == c)
			++ptr;
	}
	return (i);
}

static void			copy_strings(char ***array,
									char const *s, char c, size_t size)
{
	char			**fuckit;
	char			*ptr;
	char			**array_ptr;

	fuckit = *array + size + 1;
	array_ptr = *array;
	ptr = (char *)fuckit;
	while (size--)
	{
		*array_ptr++ = ptr;
		while (*s != c)
			*ptr++ = *s++;
		*ptr++ = '\0';
		while (*s == c)
			++s;
	}
	*array_ptr = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			len;
	size_t			size;
	char			**array;
	char			*ptr;

	ptr = (char *)s;
	size = number_of_strings(&ptr, c, &len);
	if (!(array = (char **)malloc(sizeof(char *) *
					((size + 1 + (len >> 3) + ((len % 8) != 0))))))
		return (NULL);
	copy_strings(&array, ptr, c, size);
	return (array);
}
