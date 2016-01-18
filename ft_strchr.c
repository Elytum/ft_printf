#include <string.h>
#include <stdlib.h>

char    *ft_strchr(const char *s, int c)
{
  const unsigned char *char_ptr;
  const unsigned long int *longword_ptr;
  unsigned long int longword, magic_bits, charmask;
  unsigned char c_uc;

  c_uc = (unsigned char) c;

  /* Handle the first few characters by reading one character at a time.
     Do this until CHAR_PTR is aligned on a longword boundary.  */
  for (char_ptr = (const unsigned char *) s;
       ((unsigned long int) char_ptr & (sizeof (unsigned long int) - 1)) != 0;
       ++char_ptr)
    if (*char_ptr == c_uc)
      return (void *) char_ptr;
    else if (*char_ptr == '\0')
      return NULL;
  longword_ptr = (unsigned long int *) char_ptr;
  magic_bits = -1;
  magic_bits = magic_bits / 0xff * 0xfe << 1 >> 1 | 1;

  charmask = c_uc | (c_uc << 8);
  charmask |= charmask << 16;
  if (sizeof (unsigned long int) > 4)
    charmask |= (charmask << 16) << 16;
  if (sizeof (unsigned long int) > 8)
    abort ();

  while (42)
    {

      longword = *longword_ptr++;
      if ((((longword + magic_bits) ^ ~longword) &
        ~magic_bits) != 0 || ((((longword ^ charmask) + magic_bits) ^
          ~(longword ^ charmask)) & ~magic_bits) != 0)
  {

    const unsigned char *cp = (const unsigned char *) (longword_ptr - 1);

    if (*cp == c_uc)
      return (char *) cp;
    else if (*cp == '\0')
      return NULL;
    if (*++cp == c_uc)
      return (char *) cp;
    else if (*cp == '\0')
      return NULL;
    if (*++cp == c_uc)
      return (char *) cp;
    else if (*cp == '\0')
      return NULL;
    if (*++cp == c_uc)
      return (char *) cp;
    else if (*cp == '\0')
      return NULL;
    if (sizeof (unsigned long int) > 4)
      {
        if (*++cp == c_uc)
    return (char *) cp;
        else if (*cp == '\0')
    return NULL;
        if (*++cp == c_uc)
    return (char *) cp;
        else if (*cp == '\0')
    return NULL;
        if (*++cp == c_uc)
    return (char *) cp;
        else if (*cp == '\0')
    return NULL;
        if (*++cp == c_uc)
    return (char *) cp;
        else if (*cp == '\0')
    return NULL;
      }
  }
    }

  return NULL;
}
