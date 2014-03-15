/*                                                                              
** my_cmdsplit.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:10:24 2014 bourge_v                                
** Last update Sun Mar  9 18:42:04 2014 bourge_v                                
*/

#include "minishell2.h"

static size_t   my_cmdlen(char *s)
{
  size_t        i;

  if (!s)
    return (0);
  i = 0;
  if (*s != '"')
    {
      while (my_isspace(s[i]) == 0 && s[i] != '\0')
        i++;
      return (i);
    }
  while (s[i] != '\0')
    {
      if (s[i] == '"' && (i > 0 && s[i - 1] != '\\'))
        return (i + 1);
      i++;
    }
  return (i);
}

static size_t   my_cmdnargs(char *s)
{
  size_t        i;
  size_t        n;

  if (!s)
    return (0);
  i = 0;
  n = 0;
  while (s[i] != '\0')
    {
      if (my_isspace(s[i]) == 0)
        {
          i += my_cmdlen(s + i);
          n++;
        }
      else if (my_isspace(s[i]) == 1)
        i++;
    }
  return (n);
}

static char     **my_cmdsplit_arrdel(char ***arr)
{
  my_arrdel(arr);
  return (NULL);
}

char            **my_cmdsplit(char *s)
{
  unsigned int  start;
  size_t        len;
  size_t        i;
  char          **arr;

  if (!s || my_strlen(s) == 0)
    return (NULL);
  if ((arr = my_arrnew(my_cmdnargs(s))) == NULL)
    return (NULL);
  i = 0;
  while (*s != '\0')
    {
      if (my_isspace(*s) == 1)
        s++;
      else
        {
          len = (*s != '"' ? my_cmdlen(s) : my_cmdlen(s) - 2);
          start = (*s != '"' ? 0 : 1);
          if ((arr[i] = my_strsub(s, start, len)) == NULL)
            return (my_cmdsplit_arrdel(&arr));
          i++;
          s += (*s != '"' ? len : len + 2);
        }
    }
  return (arr);
}
