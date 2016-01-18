#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# ifndef TAB_SIZE
#  define TAB_SIZE(tab) ((sizeof(tab) / sizeof(*tab)))
# endif

# define MAX_INT_SIZE 11

# define MIN_INT -2147483648
# define MIN_INT_STRING "-2147483648"

char		**ft_strsplit(char const *s, char c);
void		ft_putnbr(int i);
void		ft_putnbr_fd(int i, int fd);
char		*ft_itoa(int i);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);

char 		*ft_strchr(const char *s, int c);

#endif
