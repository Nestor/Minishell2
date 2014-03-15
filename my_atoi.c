/*                                                                              
** my_atoi.c for minishell2 in /home/bourge_v/Downloads/test/minishell2         
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:39:38 2014 bourge_v                                
** Last update Sun Mar  9 19:46:13 2014 bourge_v                                
*/

#include "minishell2.h"

static int      my_atoi_isvalid(const char *s, int i)
{
  if (my_isdigit(s[i]) == 1
      || (i == 0 && (s[i] == '-' || s[i] == '+')))
    return (1);
  return (0);
}

int             my_atoi(const char *s)
{
  int           i;
  int           sign;
  int           result;

  if (!s)
    return (0);
  i = 0;
  sign = 1;
  result = 0;
  while (my_isspace(*s) == 1)
    s++;
  while (s[i] != '\0' && my_atoi_isvalid(s, i) == 1)
    {
      if (i == 0 && s[i] == '-')
        sign = -1;
      if (my_isdigit(s[i]))
        result = s[i] - '0' + result * 10;
      i += 1;
    }
  return (result * sign);
}
