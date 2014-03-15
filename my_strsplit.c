/*                                                                              
** my_strsplit.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:10:34 2014 bourge_v                                
** Last update Sun Mar  9 20:12:40 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

static size_t   my_strsplit_arrsize(char const *s, char c)
{
  size_t        isc;
  size_t        j;
  size_t        n;

  isc = 0;
  j = 0;
  n = 0;
  if (!s)
    return (0);
  while (s[j] != '\0')
    {
      if (s[j] != c && isc == 0)
        {
          isc = 1;
          n++;
        }
      else if (s[j] == c && isc == 1)
        isc = 0;
      j++;
    }
  return (n);
}

static size_t   my_strsplit_strlen(char const *s, char c)
{
  size_t        i;

  i = 0;
  if (!s)
    return (0);
  while (s[i] != c && s[i] != '\0')
    i++;
  return (i);
}

static size_t   my_strsplit_fillarr(char **arr, char const *s, char c, size_t i\
)
{
  size_t        len;

  len = my_strsplit_strlen(s, c);
  arr[i] = my_strsub(s, 0, len);
  if (arr[i] == NULL)
    {
      my_strsplit_freearr(arr, i - 1);
      return (0);
    }
  return (len);
}

char            **my_strsplit(char const *s, char c)
{
  size_t        i;
  size_t        len;
  char          **arr;

  i = 0;
  if (!s || my_isascii(c) == 0)
    return (NULL);
  arr = my_memalloc(sizeof(char *) * (my_strsplit_arrsize(s, c) + 1));
  if (arr == NULL)
    return (NULL);
  while (*s != '\0')
    {
      if (*s == c)
        s++;
      else if (*s != c)
        {
          if ((len = my_strsplit_fillarr(arr, s, c, i)) == 0)
            return (NULL);
          s += len;
          i++;
        }
    }
  arr[i] = NULL;
  return (arr);
}
