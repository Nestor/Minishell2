/*                                                                              
** my_getcmds.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:33:33 2014 bourge_v                                
** Last update Sun Mar  9 18:44:30 2014 bourge_v                                
*/

#include "minishell2.h"

static int      my_getcmds_count(char *str, char c)
{
  int           i;
  int           n;
  int           isquote;

  if (!str || my_strlen(str) == 0)
    return (0);
  i = 0;
  n = 0;
  isquote = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"' && isquote == 0)
        isquote = 1;
      else if (str[i] == '"' && isquote == 1)
        isquote = 0;
      if (str[i] == c && isquote == 0)
        n++;
      i++;
    }
  return (n + 1);
}

static int      my_getcmds_len(char *str, char c)
{
  int           i;
  int           isquote;

  if (!str)
    return (0);
  i = 0;
  isquote = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"' && isquote == 0)
        isquote = 1;
      else if (str[i] == '"' && isquote == 1)
        isquote = 0;
      if (str[i] == c && isquote == 0)
        return (i);
      i++;
    }
  return (i);
}

static char     *my_getcmds_str(char *str, char c)
{
  int           len;
  char          *new;

  if (!str)
    return (NULL);
  len = my_getcmds_len(str, c);
  if (len == 0 && c == '|')
    return (my_strnew(0));
  new = my_strsub(str, 0, len);
  if (new == NULL)
    return (NULL);
  return (my_strtrim(new));
}

char            **my_getcmds(char *str, char c)
{
  int           i;
  int           n;
  char          **arr;

  n = my_getcmds_count(str, c);
  arr = my_arrnew(n);
  if (arr == NULL)
    return (NULL);
  i = 0;
  while (i < n)
    {
      arr[i] = my_getcmds_str(str, c);
      str += my_getcmds_len(str, c);
      str += (*str == c ? 1 : 0);
      if (arr[i] != NULL)
        i++;
    }
  return (arr);
}
